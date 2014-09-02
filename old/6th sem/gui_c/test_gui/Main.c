/*
Project name : test_gui
Created on : Tue Jan 14 21:50:51 2014
Author : Anant Pushkar
lvfbkhdvb
*/
#include <cairo.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
int debug=0;
static void do_drawing(cairo_t *);
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data){
	do_drawing(cr);
	return FALSE;
}

static void do_drawing(cairo_t *cr){ 
	//Start Drawing here
}

int main(int argc, char *argv[])
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		--argc;
		++argv;
		debug=1;
	}
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

	g_signal_connect(G_OBJECT(darea), "draw", 
	G_CALLBACK(on_draw_event), NULL);  
	g_signal_connect(window, "destroy",
	G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 460, 240); 
	gtk_window_set_title(GTK_WINDOW(window), "test_gui-Graphical Viewer");

	gtk_widget_show_all(window);
	gtk_main();
}
