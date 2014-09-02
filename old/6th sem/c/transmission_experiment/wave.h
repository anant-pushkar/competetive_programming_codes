#pragma once
struct _wave{
	int n_points;
	int *x,*y;
};
typedef struct _wave Wave;
void create_original();
Wave original;
Wave original_sample;
