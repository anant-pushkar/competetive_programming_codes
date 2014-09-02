#pragma once
#include<iostream>
#include<vector>
#include<utility>
#define DEFAULTX -1
#define DEFAULTY -1
class SeqFinder{
	std::vector<std::pair<int,int> > seqFirst;
	std::vector<std::pair<int,int> > seqSecond;
	std::vector<int> lenLookup;
	std::vector<int> preLookup;
	void populate(int);
	int findAncester(std::vector<std::pair<int,int> >,int);
public:
	SeqFinder(int);
	std::vector<std::pair<int,int> > find();
};