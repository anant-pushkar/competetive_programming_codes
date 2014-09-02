#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include<string.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>
#include"wave.h"
static void do_drawing(cairo_t *);
const int window_width=1300;
const int window_height=400;
const int ref_height=200;
const int grid_width=20;
extern int freq[5];
GtkWidget *window;
GtkWidget *darea;
int s_rate;
double *x , *y;
int graph_width=300 , *graph , graph_offset=300,fmax_est=1;
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}
void calc_graph(){
	int i,j,index,data_len,max=0;
	graph=(int*)calloc(graph_width,sizeof(int));
	int check=1;
	for(i=2;i<graph_width;++i){
		index=0;
		data_len=0;
		for(j=0;j<original.n_points;j+=i){
			x[index]=j;
			y[index]=original.y[j];
			++index;
			++data_len;
		}
		
		gsl_interp_accel *acc = gsl_interp_accel_alloc ();
		gsl_spline *spline = gsl_spline_alloc (gsl_interp_cspline, data_len);
		gsl_spline_init (spline, x, y, data_len);
		
		int yi=0;
		double err=0;
		data_len=0;
		for(j=i;j<=original.n_points-i;j+=1){
			yi=(int)gsl_spline_eval (spline, (double)j, acc);
			err+=(yi-original.y[j])*(yi-original.y[j]);
			++data_len;
		}
		gsl_spline_free (spline);
		gsl_interp_accel_free (acc);
		err=sqrt(err/data_len);
		if(check==1 && err>1){
			check=0;
			fmax_est=i;
		}
		graph[i]=10*err;
		max=max<graph[i]?graph[i]:max;
	}
	double r=((double)ref_height-10)/max;
	for(i=1;i<graph_width;++i)graph[i]=(int)(((double)graph[i])*r);
}


static void do_drawing(cairo_t *cr)
{ 
	int data_len=0;
	char str[200];
	cairo_set_source_rgb (cr, 0, 0, 0);
	
	//draw_x-axis
	cairo_move_to(cr,0,window_height/2);
	cairo_line_to(cr,window_width,window_height/2);
	cairo_stroke (cr);
	
	//draw y-axis
	cairo_move_to(cr,window_width/2,0);
	cairo_line_to(cr,window_width/2,window_height);
	cairo_stroke (cr);
	
	//draw grid
	cairo_set_line_width (cr, 0.3);
	cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); 
	int i;
	for(i=window_width/2;i<window_width;i+=grid_width){
		cairo_move_to(cr,i,0);
		cairo_line_to(cr,i,window_height);
		cairo_move_to(cr,window_width-i,0);
		cairo_line_to(cr,window_width-i,window_height);
	}
	for(i=window_height/2;i<window_height;i+=grid_width){
		cairo_move_to(cr,0,i);
		cairo_line_to(cr,window_width,i);
		cairo_move_to(cr,0,window_height-i);
		cairo_line_to(cr,window_width,window_height-i);
	}
	cairo_stroke (cr);
	
	cairo_set_line_width (cr, 1);
	//draw original
	cairo_set_source_rgb(cr, 0.3, 0.4, 0.6); 
	cairo_set_line_width (cr, 1);
	cairo_move_to(cr,original.x[0],original.y[0]);
	for(i=1;i<original.n_points;++i){
		cairo_line_to(cr,original.x[i],original.y[i]);
		cairo_move_to(cr,original.x[i],original.y[i]);
	}
	cairo_stroke (cr);
	
	//Sampling at 15
	cairo_set_source_rgb(cr, 0.8, 0.4, 0.2); 
	cairo_set_line_width (cr, 0.6);
	cairo_move_to(cr,0,window_height/2);
	
	int index=0;
	for(i=0;i<original.n_points;i+=s_rate){
		cairo_line_to(cr,i,original.y[i]);
		cairo_move_to(cr,i+s_rate,window_height/2);
		x[index]=i;
		y[index]=original.y[i];
		++index;
		++data_len;
	}
	cairo_stroke (cr);
	
	//Interpolate sampled data
	cairo_set_line_width (cr, 1);
	gsl_interp_accel *acc = gsl_interp_accel_alloc ();
	gsl_spline *spline = gsl_spline_alloc (gsl_interp_cspline, data_len);
	gsl_spline_init (spline, x, y, data_len);
	cairo_set_source_rgb(cr, 0, 0.6, 0); 
	cairo_set_line_width (cr, 1);
	cairo_move_to(cr,0,original.y[0]);
	int j=0;
	double err=0;
	data_len=0;
	cairo_move_to(cr,s_rate,(int)gsl_spline_eval (spline, (double)s_rate, acc));
	for(i=s_rate;i<=original.n_points-s_rate;i+=1){
		j=(int)gsl_spline_eval (spline, (double)i, acc);
		cairo_line_to(cr,i,j);
		cairo_move_to(cr,i,j);
		err+=(j-original.y[i])*(j-original.y[i]);
		++data_len;
	}
	gsl_spline_free (spline);
    gsl_interp_accel_free (acc);
	cairo_stroke (cr);
	
	//draw reference key
	cairo_arc(cr, 10, window_height+10,5, 0, 2 * M_PI);
	cairo_set_source_rgb(cr, 0.3, 0.4, 0.6); 
	cairo_fill(cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,20, window_height+15);
	cairo_show_text(cr,"Original Waveform");
	cairo_stroke (cr);
	
	//draw reference key
	cairo_arc(cr, 10, window_height+30,5, 0, 2 * M_PI);
	cairo_set_source_rgb(cr, 0.8, 0.4, 0.2); 
	cairo_fill(cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,20, window_height+35);
	cairo_show_text(cr,"Sampled Waveform");
	cairo_stroke (cr);
	
	//draw reference key
	cairo_arc(cr, 10, window_height+50,5, 0, 2 * M_PI);
	cairo_set_source_rgb(cr, 0, 0.6, 0); 
	cairo_fill(cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,20, window_height+55);
	cairo_show_text(cr,"Waveform interpolated from sampled waveform");
	cairo_stroke (cr);
	
	//draw buttons
	cairo_move_to(cr,5, window_height+65);
	cairo_show_text(cr,"Change Sampling rate");
	
	cairo_arc(cr, 15, window_height+80,10,0 , 2 * M_PI);
	cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
	cairo_fill(cr);
	cairo_stroke (cr);
	cairo_move_to(cr,10, window_height+84);
	cairo_set_source_rgb(cr, 1, 1, 1); 
	cairo_show_text(cr,"<");
	cairo_stroke (cr);
	
	cairo_arc(cr, 45, window_height+80,10,0 , 2 * M_PI);
	cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
	cairo_fill(cr);
	cairo_stroke (cr);
	cairo_move_to(cr,40, window_height+84);
	cairo_set_source_rgb(cr, 1, 1, 1); 
	cairo_show_text(cr,">");
	cairo_stroke (cr);
	
	calc_graph();
	cairo_move_to(cr,graph_offset,window_height+ref_height-5);
	cairo_set_source_rgb(cr, 0.5, 0.2, 0.2); 
	for(i=1;i<graph_width;++i){
		//printf("%d:%d\n",i,graph[i]);
		cairo_line_to(cr,2*i+graph_offset,window_height+ref_height-5-graph[i]);
		cairo_move_to(cr,2*i+graph_offset,window_height+ref_height-5-graph[i]);
	} 
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_move_to(cr,graph_offset,window_height+ref_height-5);
	cairo_line_to(cr,graph_width*2+graph_offset,window_height+ref_height-5);
	cairo_move_to(cr,graph_offset,window_height+ref_height-5);
	cairo_line_to(cr,graph_offset,window_height+5);
	cairo_move_to(cr,graph_offset-40,window_height+ref_height/2);
	cairo_show_text(cr,"Error");
	cairo_move_to(cr,graph_offset+2*graph_width+5,window_height+ref_height-5);
	cairo_show_text(cr,"Sampling Time Period");
	cairo_stroke (cr);
	int min=1000000;
	char freq_list[1000];
	sprintf(freq_list,"Constituent time Periods : ");
	for(i=0;i<5;++i){
		min=freq[i]<min?freq[i]:min;
		sprintf(str," %d",freq[i]);
		strcat(freq_list,str);
	}
	cairo_move_to(cr,5,window_height+105);
	cairo_show_text(cr,freq_list);
	cairo_move_to(cr,5,window_height+115);
	sprintf(freq_list,"Present Sampling time period : %d units",s_rate);
	cairo_show_text(cr,freq_list);
	min=min/2;
	cairo_set_source_rgb(cr, 0.1, 0.1, 0.9);
	cairo_move_to(cr,graph_offset+2*s_rate,window_height+ref_height-5);
	cairo_line_to(cr,graph_offset+2*s_rate,window_height+5);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0.9, 0.1, 0.1);
	cairo_move_to(cr,graph_offset+2*min,window_height+ref_height-5);
	cairo_line_to(cr,graph_offset+2*min,window_height+5);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0.1, 0.9, 0.1);
	cairo_move_to(cr,graph_offset+2*fmax_est,window_height+ref_height-5);
	cairo_line_to(cr,graph_offset+2*fmax_est,window_height+5);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,graph_offset+2*graph_width+20,window_height+10);
	sprintf(str,"Actual fmax : %d units (fmax/2 shown on graph)",(50000/min));
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0.9, 0.1, 0.1);
	cairo_move_to(cr,graph_offset+2*graph_width+17,window_height);
	cairo_line_to(cr,graph_offset+2*graph_width+17,window_height+10);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,graph_offset+2*graph_width+20,window_height+30);
	sprintf(str,"Estimated fmax : %d units (fmax/2 shown on graph)",(50000/fmax_est));
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0.1, 0.9, 0.1);
	cairo_move_to(cr,graph_offset+2*graph_width+17,window_height+20);
	cairo_line_to(cr,graph_offset+2*graph_width+17,window_height+30);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,graph_offset+2*graph_width+20,window_height+50);
	sprintf(str,"Present Sampling Frequnecy : %d units",(100000/s_rate));
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0.1, 0.1, 0.9);
	cairo_move_to(cr,graph_offset+2*graph_width+17,window_height+40);
	cairo_line_to(cr,graph_offset+2*graph_width+17,window_height+50);
	cairo_stroke (cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,graph_offset+2*graph_width+20,window_height+70);
	sprintf(str,"Percentage error (in estimation of fmax): %f",100*((double)(fmax_est-min)/min));
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	
	//print error
	err=sqrt(err/data_len);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,65, window_height+80);
	sprintf(str,"Mean Squared error : %f",err);
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	
	cairo_set_font_size (cr,20);
	cairo_move_to(cr,10,20);
	cairo_show_text(cr,"Original Waveform and Waveform interpolated from sampled waveforms");
	cairo_set_font_size (cr,15);
	cairo_move_to(cr,graph_offset+10+graph_width,window_height+ref_height-20);
	cairo_show_text(cr,"Error Vs Sampling time period");
}
void button_clicked(GtkWidget *widget,GdkEventButton  *event,gpointer   user_data)
{
  if(event->x>=10 && event->x<=25 && event->y>=470 && event->y<=490 && s_rate>1)s_rate-=1;
  if(event->x>=40 && event->x<=55 && event->y>=470 && event->y<=490 && s_rate<graph_width)s_rate+=1;
  gtk_widget_queue_draw_area (darea,0,0,window_width,window_height+ref_height);
}
void draw_screen(int argc, char *argv[])
{
	s_rate=10;
	gtk_init(&argc, &argv);
	x=(double*)calloc(original.n_points,sizeof(double));
	y=(double*)calloc(original.n_points,sizeof(double)) ;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

	g_signal_connect(G_OBJECT(darea), "draw", 
		G_CALLBACK(on_draw_event), NULL);  
	gtk_widget_add_events(darea, GDK_BUTTON_PRESS_MASK);
	g_signal_connect(G_OBJECT(darea), "button-press-event", 
		G_CALLBACK(button_clicked), NULL);
	g_signal_connect(window, "destroy",
		G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_set_size_request(GTK_WIDGET(window), window_width, window_height+ref_height); 
	gtk_window_set_title(GTK_WINDOW(window), "Graphical Viewer");
	gtk_window_set_resizable(GTK_WINDOW (window), FALSE);

	gtk_widget_show_all(window);
	gtk_window_set_modal (GTK_WINDOW(window),TRUE);
	gtk_main();
}
