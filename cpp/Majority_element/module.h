/*
Project name : Majority_element
Module name  : module
Created on : Thu Aug  7 18:58:38 2014
Author : Anant Pushkar
Explore algorithms to find majority element in an array
*/
#pragma once
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<ctime>

const int max_val = 10000;
typedef long long int lld;
typedef unsigned long long int llu;

class MajorityFinder{
	std::vector<int> arr;
	int size;
	std::pair<int,int> divide(int start , int end);
	void handle_exp(int exp) const throw(int);
	int find_majority() throw(int);
	int get_contestant();
	bool is_majority(int );
public:
	MajorityFinder(int );
	MajorityFinder(int a[] , int );
	int get_majority() throw(int);
	void report_error(int exp);
};


