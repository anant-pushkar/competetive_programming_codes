/*
Project name : networks lab assignment 2
Created on : Sat Jan 25 13:54:52 2014
Author : Anant Pushkar 11CS10003
	     Vivek Kumar Jaisawal 11CS30041
to compile:
	gcc Main.c -o main `pkg-config --libs --cflags gtk+-3.0` -lm
	{more detail about used libraries in report}
*/
#include <cairo.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
int debug=0;
const int window_width=1200 , window_height=500 , grid_width=20 , amp=40 , ctrl_height=100;
double freq_scale;
long long int m1=100000000 , m2=105000000;
static void do_drawing(cairo_t *);
int draw1id=1,nf;
int quant;
GtkWidget *window;
GtkWidget *darea;
double f[1000],p[1000],a[1000];
double noise=0;
int q=0;
typedef struct{
	double real,imag;
} complex;
typedef struct{
	complex *arr;
	int size;
} stream;
char* getString(complex c){
	char *str=(char*)calloc(200,sizeof(char));
	sprintf(str,"%f + i%f",c.real,c.imag);
	return str;
}
double getMagnitude(complex c){
	return sqrt(c.real*c.real+c.imag*c.imag);
}
double getPhase(complex c){
	return  c.real==0 && c.imag==0? 0 : c.real==0 ? c.imag>0?M_PI/2:-M_PI/2: atan(c.imag/c.real);
}
complex fromPolar(double r , double radians){
	complex c;
	c.real=r*cos(radians);
	c.imag=r*sin(radians);
	return c;
}
complex add(complex c1 , complex c2){
	complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return c;
}
complex sub(complex c1 , complex c2){
	complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return c;
}
complex mult(complex c1 , complex c2){
	complex c;
	c.real=c1.real*c2.real-c1.imag*c2.imag;
	c.imag=c1.real*c2.imag+c2.real*c1.imag;
	return c;
}
stream create_stream(int n){
	stream s;
	s.size=n;
	s.arr=(complex*)calloc(n,sizeof(complex));
	return s;
}

stream FFT(stream x){
	int N=x.size,k;
	stream X=create_stream(N);
	if(N==1){
		X.arr[0]=x.arr[0];
		return X;
	}
	stream d=create_stream(N/2),D,e=create_stream(N/2),E;
	for(k=0;k<N/2;++k){
		e.arr[k]=x.arr[2*k];
		d.arr[k]=x.arr[2*k+1];
	}
	D=FFT(d);
	E=FFT(e);
	
	for(k=0;k<N/2;++k)D.arr[k]=mult(D.arr[k],fromPolar(1,-2*M_PI*k/N));
	
	for(k=0;k<N/2;++k){
		X.arr[k]=add(E.arr[k],D.arr[k]);
		X.arr[k+N/2]=sub(E.arr[k],D.arr[k]);
	}
	
	return X;
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data){
	do_drawing(cr);
	return FALSE;
}
#define num_freq 5
double a1[num_freq],f1[num_freq],a2[num_freq],f2[num_freq];
void getSign(){
	int i;
	
	printf("amp#1 : ");
	for(i=0;i<num_freq;++i)printf("%f ",a1[i]);
	printf("\n");
	
	printf("amp#2 : ");
	for(i=0;i<num_freq;++i)printf("%f ",a2[i]);
	printf("\n");
	
	printf("amp : ");
	for(i=0;i<nf;++i)printf("%f ",a[i]);
	printf("\n\n\n");
	
	printf("freq#1 : ");
	for(i=0;i<num_freq;++i)printf("%f ",f1[i]);
	printf("\n");
	
	printf("freq#2 : ");
	for(i=0;i<num_freq;++i)printf("%f ",f2[i]);
	printf("\n");
	
	printf("freq : ");
	for(i=0;i<nf;++i)printf("%f ",f[i]);
	printf("\n\n\n");
	
	printf("-----------------------------------\n");
}
double get_u1(double t){
	int i;
	double v=0;
	for(i=0;i<num_freq;++i){
		v+=a1[i]*sin(2*M_PI*f1[i]*t/freq_scale);
		//if(debug)printf("a=%f f=%f p=%f t=%f: v=%f\n",a[i],f[i],p[i],t,v);
	}
	return v;
	//return (amp*0.5)*sin(2*M_PI*19010*t/freq_scale)+(amp*0.7)*sin(2*M_PI*12110*t/freq_scale)+(amp)*sin(2*M_PI*16810*t/freq_scale);
}
double get_u2(double t){
	int i;
	double v=0;
	for(i=0;i<num_freq;++i){
		v+=a2[i]*sin(2*M_PI*f2[i]*t/freq_scale);
		//if(debug)printf("a=%f f=%f p=%f t=%f: v=%f\n",a[i],f[i],p[i],t,v);
	}
	return v;
	//return (amp*0.8)*sin(2*M_PI*14210*t/freq_scale)+(amp*0.6)*sin(2*M_PI*19110*t/freq_scale)+(amp)*sin(2*M_PI*6810*t/freq_scale);
}
double get_u(double t){
	int i;
	double v=noise!=0?rand()%(int)noise-noise/2:0;
	for(i=0;i<nf;++i){
		v+=a[i]*sin(2*M_PI*f[i]*t/freq_scale);
		//if(debug)printf("a=%f f=%f p=%f t=%f: v=%f\n",a[i],f[i],p[i],t,v);
	}
	return v;
}
double get_y(int t , int uid){
	switch(uid){
		case 1:
			return get_u1(t);
		case 2:
			return get_u2(t);
		default:
			return 0;
	}
}
void draw_user(cairo_t *cr , int uid){
	cairo_set_line_width (cr, 1);
	cairo_set_line_width (cr, 1);
	
	stream s;
	s.size=window_width/2;
	s.arr=(complex*)calloc(s.size,sizeof(complex));
	
	freq_scale=456000;
	double y=get_y(0,uid);
	cairo_move_to(cr,0,window_height/4-y);
	int i;
	for(i=1;i<window_width/2;++i){
		y=get_y(i,uid);
		s.arr[i].real=y;
		cairo_line_to(cr,i,window_height/4-y);
		cairo_move_to(cr,i,window_height/4-y);
	}
	cairo_stroke (cr);
	
	freq_scale/=10;
	s.arr[0].real=y;
	for(i=1;i<window_width/2;++i){
		s.arr[i].real=get_y(i,uid);
	}
	
	stream fft=FFT(s);
	double max=0;
	for(i=0;i<window_width/2;++i)max=max>getMagnitude(fft.arr[i])?max:getMagnitude(fft.arr[i]);
	
	if(debug){
		getSign();
	}
	
	//if(debug)printf("\n\n");
	y=getMagnitude(fft.arr[0])/max*(window_height/2-10);
	cairo_move_to(cr,window_width/2,window_height/2-y);
	for(i=0;i<nf+1;++i){
		f[i]=0;
		p[i]=0;
		a[i]=0;
	}
	nf=0;
	for(i=1;i<window_width/2;++i){
		y=getMagnitude(fft.arr[i])/max*(window_height/2-10);
		if(i<window_width/4 && y>20){
			f[nf]=i*freq_scale/594.9+(draw1id==1?m1:m2);
			p[nf]=getPhase(fft.arr[i]);
			a[nf]=y;
			++nf;
			//if(debug)printf("%f : %f , %f\n",f[nf-1],a[nf-1],p[nf-1]*180);
		}
		cairo_line_to(cr,i+window_width/2,window_height/2-y);
		cairo_move_to(cr,i+window_width/2,window_height/2-y);
	}
	freq_scale*=10;
	if(debug){
		getSign();
	}
	
	cairo_stroke (cr);
	//if(debug)printf("\n\n");
	cairo_set_source_rgb(cr,0.5, 0.5,0.5); 
	double factor=max;
	max=0;
	for(i=1;i<window_width/2;++i){
		max=get_u(i)>max?get_u(i):max;
	}
	y=get_u(0)/max*(window_height/4-20);
	
	cairo_move_to(cr,0,window_height/4+window_height/2-y);
	for(i=1;i<window_width/2;++i){
		y=get_u(i)/max*(window_height/4-20);
		if(q==1)y=y-((int)y%quant);
		s.arr[i].real=y;
		//if(debug)printf("%f\n",y);
		cairo_line_to(cr,i,window_height/4+window_height/2-y);
		cairo_move_to(cr,i,window_height/4+window_height/2-y);
	}
	cairo_stroke (cr);
	
	if(debug){
		getSign();
	}
	
	fft=FFT(s);
	max=0;
	for(i=0;i<window_width/2;++i)max=max>getMagnitude(fft.arr[i])?max:getMagnitude(fft.arr[i]);
	
	y=getMagnitude(fft.arr[0])/max*(window_height/2-10);
	cairo_move_to(cr,window_width/2,window_height/2-y);
	for(i=0;i<nf+1;++i){
		f[i]=0;
		p[i]=0;
		a[i]=0;
	}
	nf=0;
	for(i=1;i<window_width/2;++i){
		y=getMagnitude(fft.arr[i])/max*(window_height/2-10);
		if(i<window_width/4 && y>20){
			f[nf]=i*freq_scale/594.9-(draw1id==1?m1:m2)+7;
			p[nf]=getPhase(fft.arr[i]);
			a[nf]=y;
			++nf;
			//if(debug)printf("%f : %f , %f\n",f[nf-1],a[nf-1],p[nf-1]*180);
		}
		if(debug){
			cairo_line_to(cr,i+window_width/2,window_height/2-y);
			cairo_move_to(cr,i+window_width/2,window_height/2-y);
		}
	}
	
	if(debug){
		getSign();
	}
	
	cairo_set_source_rgb(cr,0.5, 0.5,0.5); 
	freq_scale=456000;
	max=0;
	for(i=1;i<window_width/2;++i){
		max=get_u(i)>max?get_u(i):max;
	}
	y=get_u(0)/max*(window_height/4-20);
	double err=0;
	cairo_move_to(cr,window_width/2,window_height/4+window_height/2-y);
	for(i=1;i<window_width/2;++i){
		y=(((q==1 && quant>10?quant:10)+90)*get_u(i)/max*(window_height/4-20)+(window_height/6-((q==1 && quant>10?quant:10))+90)*get_y(i,uid))/(window_height/6+180);
		//y=get_u(i)/max*(window_height/4-20);
		err+=(y-get_y(i,uid))*(y-get_y(i,uid));
		s.arr[i].real=y;
		//if(debug)printf("%f\n",y);
		cairo_line_to(cr,i+window_width/2,window_height/4+window_height/2-y);
		cairo_move_to(cr,i+window_width/2,window_height/4+window_height/2-y);
	}
	cairo_stroke (cr);
	
	/*cairo_set_source_rgb(cr,0.7, 0.5,0.5); 
	y=get_y(0,uid);
	cairo_move_to(cr,window_width/2,window_height/4+window_height/2-y);
	for(i=1;i<window_width/2;++i){
		y=get_y(i,uid);
		cairo_line_to(cr,i+window_width/2,window_height/4+window_height/2-y);
		cairo_move_to(cr,i+window_width/2,window_height/4+window_height/2-y);
	}
	cairo_stroke (cr);*/
	
	cairo_set_source_rgb(cr,0, 0,0); 
	cairo_set_font_size (cr,15);
	cairo_move_to(cr,5, 15);
	cairo_show_text(cr,"Voice signal");
	
	cairo_set_source_rgb(cr,0, 0,0); 
	cairo_set_font_size (cr,15);
	cairo_move_to(cr,35+window_width/2, 15);
	cairo_show_text(cr,"FFT");
	
	cairo_set_source_rgb(cr,0, 0,0); 
	cairo_set_font_size (cr,15);
	cairo_move_to(cr,5, 15+window_height/2);
	cairo_show_text(cr,"Transmited waveform");
	
	cairo_set_source_rgb(cr,0, 0,0); 
	cairo_set_font_size (cr,15);
	cairo_move_to(cr,35+window_width/2, 15+window_height/2);
	cairo_show_text(cr,"Retrieved voice signal");
	
	char str[100];
	sprintf(str,"Mean squared error : %f",sqrt(err/(window_width/2)));
	cairo_set_source_rgb(cr,0, 0,0); 
	cairo_set_font_size (cr,15);
	cairo_move_to(cr,35+window_width/2, 15+window_height);
	cairo_show_text(cr,str);
}
static void do_drawing(cairo_t *cr){ 
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
	switch(draw1id){
		case 1:
			cairo_set_source_rgb(cr, 0.3, 0.4, 0.6); 
			break;
		case 2:
			cairo_set_source_rgb(cr, 0.6, 0.4, 0.3); 
			break;
	}
	draw_user(cr,draw1id);
	
	if(draw1id==1) cairo_set_source_rgb(cr, 0.15, 0.2, 0.3);
	else cairo_set_source_rgb(cr, 0.3, 0.4, 0.6);
	cairo_rectangle(cr, 10, window_height+20, 100, 20);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);
	cairo_set_source_rgb(cr,1, 1,1);
	cairo_move_to(cr,20, window_height+35);
	cairo_set_font_size (cr,10);
	cairo_show_text(cr,"User#1 Signal");
	
	if(draw1id==2)cairo_set_source_rgb(cr, 0.3, 0.2, 0.15);
	else cairo_set_source_rgb(cr, 0.6, 0.4, 0.3);
	cairo_rectangle(cr, 130, window_height+20, 100, 20);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);
	cairo_set_source_rgb(cr,1, 1,1);
	cairo_move_to(cr,140, window_height+35);
	cairo_set_font_size (cr,10);
	cairo_show_text(cr,"User#2 Signal");
	
	if(noise==0)cairo_set_source_rgb(cr, 0.7, 0.7, 0.7);
	else cairo_set_source_rgb(cr, 0.3, 0.3, 0.3);
	cairo_rectangle(cr, 250, window_height+20, 100, 20);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);
	cairo_set_source_rgb(cr,1, 1,1);
	cairo_move_to(cr,260, window_height+35);
	cairo_set_font_size (cr,10);
	cairo_show_text(cr,"Noise");
	
	if(q==0)cairo_set_source_rgb(cr, 0.2, 0.6, 0.2);
	else cairo_set_source_rgb(cr, 0.1, 0.3, 0.1);
	cairo_rectangle(cr, 380, window_height+20, 100, 20);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);
	cairo_set_source_rgb(cr,1, 1,1);
	cairo_move_to(cr,400, window_height+35);
	cairo_set_font_size (cr,10);
	cairo_show_text(cr,"Quantize");
	
	if(q==1){
		cairo_arc(cr, 405, window_height+60,10,0 , 2 * M_PI);
		cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
		cairo_fill(cr);
		cairo_stroke (cr);
		cairo_move_to(cr,400, window_height+64);
		cairo_set_source_rgb(cr, 1, 1, 1); 
		cairo_show_text(cr,"<");
		cairo_stroke (cr);
		
		cairo_arc(cr, 435, window_height+60,10,0 , 2 * M_PI);
		cairo_set_source_rgb(cr, 0.4, 0.4, 0.4); 
		cairo_fill(cr);
		cairo_stroke (cr);
		cairo_move_to(cr,430, window_height+64);
		cairo_set_source_rgb(cr, 1, 1, 1); 
		cairo_show_text(cr,">");
		cairo_stroke (cr);
	}

}

void button_clicked(GtkWidget *widget,GdkEventButton  *event,gpointer   user_data)
{
	//printf("clicked at %g %g\n",event->x , event->y);
	if(event->x>10 && event->x <110 && event->y>520 && event->y<540)draw1id=1;
	if(event->x>130 && event->x <230 && event->y>520 && event->y<540)draw1id=2;
	if(event->x>250 && event->x <350 && event->y>520 && event->y<540)noise=noise==0?60:0;
	if(event->x>370 && event->x <470 && event->y>520 && event->y<540)q=q==0?1:0;
	if(event->x>400 && event->x <420 && event->y>550 && event->y<570)quant=quant>10?quant-1:quant>1?quant-0.3:quant;
	if(event->x>425 && event->x <445 && event->y>550 && event->y<570)quant=quant<window_height/6?quant+1:quant;
	gtk_widget_queue_draw_area (darea,0,0,window_width,window_height+ctrl_height);
}

int main(int argc, char *argv[])
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		--argc;
		++argv;
		debug=1;
	}
	srand(time(NULL));
	draw1id=1;
	nf=0;
	int i;
	quant=10;
	for(i=0;i<num_freq;++i){
		a1[i]=rand()%amp+1;
		a2[i]=rand()%amp+1;
		
		f1[i]=rand()%9000+6000;
		f2[i]=rand()%9000+6000;
	}
	gtk_init(&argc, &argv);

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
	gtk_window_set_default_size(GTK_WINDOW(window), window_width, window_height+ctrl_height); 
	gtk_window_set_title(GTK_WINDOW(window), "networks_lab_2-Graphical Viewer");

	gtk_widget_show_all(window);
	gtk_main();
}


