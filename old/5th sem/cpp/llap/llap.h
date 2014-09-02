#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include<time.h>
class LlapFinder{
	std::vector<int> arr,lookupLen,lookupPre;
	int  length;//length of LLAP
	void find();
	int  maxIndex(int start , int end);
	int  genMaxLen(int start , int end);
	int  len;//length of input array
	std::vector<int> llap;
	void preprocess();
public:
	LlapFinder();
	void read();
	int getLength();
	void print();
	void generate(int);
};