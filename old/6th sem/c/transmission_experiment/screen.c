#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include<string.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>
#include"wave.h"
#include<time.h>
static void do_drawing(cairo_t *);
const int window_width=1200;
const int window_height=400;
const int ref_height = 200;
const int col_width=300;
int q_rate=10;
GtkWidget *window;
GtkWidget *darea;
int s_rate=10;
int n_max=10;
double *x , *y;
extern int freq[5];
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}
static void do_drawing(cairo_t *cr)
{ 
	int i,data_len;
	char str[50];
	//x-axis
	cairo_set_source_rgb(cr, 0.7, 0.7, 0.7); 
	cairo_move_to(cr,0,window_height/2);
	cairo_line_to(cr,window_width,window_height/2);
	cairo_stroke (cr);
	
	//quantum levels
	cairo_set_line_width (cr, 0.3);
	cairo_set_source_rgb(cr, 0.7, 0.7, 0.7); 
	for(i=window_height/2-q_rate;i>=0;i-=q_rate){
		cairo_move_to(cr,0,i);
		cairo_line_to(cr,window_width,i);
	}
	cairo_stroke (cr);
	for(i=window_height/2+q_rate;i<=window_height;i+=q_rate){
		cairo_move_to(cr,0,i);
		cairo_line_to(cr,window_width,i);
	}
	cairo_stroke (cr);
	
	cairo_set_line_width (cr, 1);
	cairo_set_source_rgb(cr, 0,0,0); 
	cairo_move_to(cr,10,20);
	cairo_set_font_size (cr,20);
	cairo_show_text(cr,"Original composite waveform");
	
	cairo_move_to(cr,window_width/2,window_height);
	cairo_line_to(cr,window_width/2,0);
	cairo_stroke(cr);
	
	cairo_move_to(cr,10+window_width/2,20);
	cairo_set_font_size (cr,20);
	cairo_show_text(cr,"Interpolated waveform after reception");
	
	cairo_set_source_rgb(cr, 0.3, 0.4, 0.6); 
	cairo_set_line_width (cr, 1);
	cairo_move_to(cr,original.x[0],original.y[0]);
	for(i=1;i<original.n_points;++i){
		cairo_line_to(cr,original.x[i],original.y[i]);
		cairo_move_to(cr,original.x[i],original.y[i]);
	}
	cairo_stroke (cr);
	
	cairo_set_source_rgb(cr, 0.8, 0.4, 0.2); 
	cairo_set_line_width (cr, 0.6);
	cairo_move_to(cr,0,window_height/2);
	
	int index=0;
	data_len=0;
	for(i=0;i<original.n_points;i+=s_rate){
		cairo_line_to(cr,i,original.y[i]-((original.y[i]-window_height/2)%q_rate));
		cairo_move_to(cr,i+s_rate,window_height/2);
		x[index]=i;
		y[index]=original.y[i]-(original.y[i]%q_rate)+rand()%n_max-n_max/2;
		++index;
		++data_len;
	}
	cairo_stroke (cr);
	
	cairo_set_source_rgb(cr, 0.6, 0.6, 0.3); 
	cairo_move_to(cr,window_width/2,window_height/2);
	index=0;
	for(i=0;i<original.n_points;i+=s_rate){
		cairo_line_to(cr,i+window_width/2,y[index]-(((int)y[index]-window_height/2)%q_rate));
		cairo_move_to(cr,i+s_rate+window_width/2,window_height/2);
		++index;
	}
	cairo_stroke (cr);
	
	//Interpolate sampled data
	cairo_set_line_width (cr, 1);
	gsl_interp_accel *acc = gsl_interp_accel_alloc ();
	gsl_spline *spline = gsl_spline_alloc (gsl_interp_cspline, data_len);
	gsl_spline_init (spline, x, y, data_len);
	cairo_set_source_rgb(cr, 0, 0.6, 0); 
	cairo_set_line_width (cr, 1);
	cairo_move_to(cr,window_width/2,original.y[0]);
	int j=0;
	double err=0;
	data_len=0;
	cairo_move_to(cr,s_rate+window_width/2,(int)gsl_spline_eval (spline, (double)s_rate, acc));
	for(i=s_rate;i<=original.n_points-s_rate;i+=1){
		j=(int)gsl_spline_eval (spline, (double)i, acc);
		cairo_line_to(cr,i+window_width/2,j);
		cairo_move_to(cr,i+window_width/2,j);
		err+=(j-original.y[i])*(j-original.y[i]);
		++data_len;
	}
	gsl_spline_free (spline);
    gsl_interp_accel_free (acc);
	cairo_stroke (cr);
	
	//draw reference key
	cairo_set_font_size (cr,10);
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
	cairo_show_text(cr,"Waveform interpolated from received waveform");
	cairo_stroke (cr);
	
	//draw reference key
	cairo_arc(cr, 10, window_height+70,5, 0, 2 * M_PI);
	cairo_set_source_rgb(cr, 0.6, 0.6, 0.3); 
	cairo_fill(cr);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,20, window_height+75);
	cairo_show_text(cr,"Received waveform");
	cairo_stroke (cr);
	
	err=sqrt(err/data_len);
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,20, window_height+95);
	sprintf(str,"Mean Sqaured Error : %f",err);
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	
	//draw buttons
	cairo_move_to(cr,col_width-5, window_height+10);
	cairo_show_text(cr,"Change Sampling rate");
	cairo_stroke (cr);
	
	cairo_arc(cr, 15+col_width, window_height+30,10,0 , 2 * M_PI);
	cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
	cairo_fill(cr);
	cairo_stroke (cr);
	cairo_move_to(cr,10+col_width, window_height+34);
	cairo_set_source_rgb(cr, 1, 1, 1); 
	cairo_show_text(cr,"<");
	cairo_stroke (cr);
	
	cairo_arc(cr, 45+col_width, window_height+30,10,0 , 2 * M_PI);
	cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
	cairo_fill(cr);
	cairo_stroke (cr);
	cairo_move_to(cr,40+col_width, window_height+34);
	cairo_set_source_rgb(cr, 1, 1, 1); 
	cairo_show_text(cr,">");
	cairo_stroke (cr);
	
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,col_width-5,window_height+55);
	sprintf(str,"Present Sampling time period : %d units",s_rate);
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	
	//draw buttons
	cairo_move_to(cr,col_width-5, window_height+70);
	cairo_show_text(cr,"Change Quantization width");
	cairo_stroke (cr);
	
	cairo_arc(cr, 15+col_width, window_height+90,10,0 , 2 * M_PI);
	cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
	cairo_fill(cr);
	cairo_stroke (cr);
	cairo_move_to(cr,10+col_width, window_height+94);
	cairo_set_source_rgb(cr, 1, 1, 1); 
	cairo_show_text(cr,"<");
	cairo_stroke (cr);
	
	cairo_arc(cr, 45+col_width, window_height+90,10,0 , 2 * M_PI);
	cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
	cairo_fill(cr);
	cairo_stroke (cr);
	cairo_move_to(cr,40+col_width, window_height+94);
	cairo_set_source_rgb(cr, 1, 1, 1); 
	cairo_show_text(cr,">");
	cairo_stroke (cr);
	
	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_move_to(cr,col_width-5,window_height+115);
	sprintf(str,"Present Quantization width : %d units",q_rate);
	cairo_show_text(cr,str);
	cairo_stroke (cr);
	
	int min=1000000;
	char freq_list[1000];
	sprintf(freq_list,"Constituent time Periods : ");
	for(i=0;i<5;++i){
		min=freq[i]<min?freq[i]:min;
		sprintf(str," %d",freq[i]);
		strcat(freq_list,str);
	}
	cairo_move_to(cr,20,window_height+105);
	cairo_show_text(cr,freq_list);
}
void button_clicked(GtkWidget *widget,GdkEventButton  *event,gpointer   user_data)
{
  //printf("clicked at %g %g\n",event->x,event->y);
  if(event->x>=col_width+3 && event->x<=col_width+25 && event->y>=420 && event->y<=440 && s_rate>1)s_rate-=1;
  if(event->x>=col_width+40 && event->x<=col_width+55 && event->y>=420 && event->y<=440 && s_rate<window_width/2)s_rate+=1;
   if(event->x>=col_width+3 && event->x<=col_width+25 && event->y>=480 && event->y<=500 && q_rate>1)q_rate-=1;
  if(event->x>=col_width+40 && event->x<=col_width+55 && event->y>=480 && event->y<=500 && q_rate<window_height/4)q_rate+=1;
  gtk_widget_queue_draw_area (darea,0,0,window_width,window_height+ref_height);
}
void draw_screen(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	srand(time(NULL));
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
