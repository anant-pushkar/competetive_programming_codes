#pragma once
#include<iostream>
#include<vector>
class SubSequenceFinder{
	std::vector< std::vector<int> > lookup;
	int length;
	std::string subSequence;
	void printLookup();
public:
	SubSequenceFinder(std::string,std::string);
	int getLength();
};