/*
Project name : num_to_str_indian_
Created on : Thu Oct 16 17:58:07 2014
Author : Anant Pushkar

*/
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
vector<string> face;
void init(){
	vector<string>face_one(10);
	face_one[0] = "zero";
	face_one[1] = "one";
	face_one[2] = "two";
	face_one[3] = "three";
	face_one[4] = "four";
	face_one[5] = "five";
	face_one[6] = "six";
	face_one[7] = "seven";
	face_one[8] = "eight";
	face_one[9] = "nine";
	
	vector<string>face_ten(10);
	face_ten[0] = "";
	face_ten[1] = "";
	face_ten[2] = "twenty";
	face_ten[3] = "thirty";
	face_ten[4] = "forty";
	face_ten[5] = "fifty";
	face_ten[6] = "sixty";
	face_ten[7] = "seventy";
	face_ten[8] = "eighty";
	face_ten[9] = "ninty";
	
	face = vector<string>(100);
	for(int i=0;i<10;++i){
		face[i] = face_one[i];
	}
	face[10] = "ten";
	face[11] = "eleven";
	face[12] = "twelve";
	face[13] = "thirteen";
	face[14] = "fourteen";
	face[15] = "fifteen";
	face[16] = "sixteen";
	face[17] = "seventeen";
	face[18] = "eighteen";
	face[19] = "ninteen";
	
	for(int i=20;i<100;++i){
		if(i%10==0){
			face[i] = face_ten[i/10];
		}else{
			face[i] = face_ten[i/10] + " " + face_one[i%10];
		}
	}
}
bool check;
void print_num(int n ){
	if(n<100){
		if(check)cout<<"and ";
		cout<<face[n];
		return;
	}
	check = true;
	if(n<1000){
		if(n/100!=0){
			cout<<face[n/100]<<" hundred ";
			if(n%100!=0){
				print_num(n%100);
			}
		}
		return;
	}else if(n<100000){
		cout<<face[n/1000]<<" thousand ";
		if(n%1000!=0){
			print_num(n%1000);
		}
		return;
	}else if(n<10000000){
		cout<<face[n/100000]<<" lakh ";
		if(n%100000!=0){
			print_num(n%100000);
		}
		return;
	}else if(n<1000000000){
		cout<<face[n/10000000]<<" crore ";
		if(n%10000000!=0){
			print_num(n%10000000);
		}
		return;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	init();
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		scanf("%d",&n);
		check = false;
		print_num(n);
		cout<<endl;
	}
	
	return 0;
}

