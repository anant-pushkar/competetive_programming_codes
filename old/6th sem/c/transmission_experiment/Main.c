/*
Project name : transmission_experiment
Created on : Sun Jan 12 14:44:44 2014
Author : Anant Pushkar
Dummy project for network lab 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"wave.h"
#include<time.h>
#include <gtk/gtk.h>
int debug=0;
extern Wave original;
extern int freq[5];
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		--argc;
		++argv;
		debug=1;
	}
	srand(time(NULL));
	int i;
	create_original();
	draw_screen(argc,argv);
	return 0;
}