/*
Project name : mt_ass_2
Created on : Thu Jan 30 21:44:03 2014
Author : Anant Pushkar
os ass2 test
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <ctime>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>
#define getRand(x,y) (rand()%((y)-(x)+1)+(x))
#define log2(x) (log(x)/log(2))
using namespace std;
bool debug=false;
class Complex{
public:
	double real,imag;
	
	Complex(const Complex &c):
	real(c.real),
	imag(c.imag){}
	
	Complex():
	real(0),
	imag(0){}
	
	Complex(double r):
	real(r),
	imag(0){}
	
	Complex(double r , double im):
	real(r),
	imag(im){}
	
	string toString(){
		char str[100];
		sprintf(str,"%f + %fi",real,imag);
		return string(str);
	}
	
	double magnitude(){
		return sqrt(real*real+imag*imag);
	}
	
	double phase() const {
		return real==0 && imag!=0? imag>0?M_PI/2:-M_PI/2 : imag==0 && real!=0? real>0?0:M_PI : atan(imag/real);
	}
};
Complex fromPolar(double r , double radians){
	return Complex(r*cos(radians),r*sin(radians));
}
Complex operator+(const Complex &c1 , const Complex &c2){
	return Complex(c1.real+c2.real , c1.imag+c2.imag);
}

Complex operator-(const Complex &c1 , const Complex &c2){
	return Complex(c1.real-c2.real , c1.imag-c2.imag);
}

Complex operator*(const Complex &c1 , const Complex &c2){
	return Complex(c1.real*c2.real-c1.imag*c2.imag,c1.real*c2.imag+c2.real*c1.imag);
}
typedef struct compositeSignal{
	int *frequency;
	int *amplitude;
	int num;
	int minFreq;
	int maxFreq;
	int lcmVal;


	compositeSignal(int n)
		{
			frequency = new int(n);
			amplitude = new int(n);
			num = n;
			minFreq = INT_MAX;
			maxFreq = 0;
			lcmVal = 0;
			for(int i=0;i<num;i++)
			{
				amplitude[i] = getRand(1,1000);
				//cout<<amplitude[i]<<" "<<endl;
				frequency[i] = getRand(1000,16000);
				minFreq = min(minFreq, frequency[i]);
				maxFreq = max(maxFreq, frequency[i]);
				cout<<frequency[i]<<" ";
			}
			cout<<endl;
		}
	
		
	double getVal(double t)
		{
			double val = 0;
			for(int i = 0;i<num;i++)
				val += amplitude[i]*sin(2*3.14*frequency[i]*t);
			return val;
		}
}compositeSignal;


vector<Complex> FFT(vector<Complex> x){
	int N=x.size();
	vector<Complex> X(N);
	if(N==1){
		X[0]=x[0];
		return X;
	}
	vector<Complex> d(N/2),D,e(N/2),E;
	for(int k=0;k<N/2;++k){
		e[k]=x[2*k];
		d[k]=x[2*k+1];
	}
	D=FFT(d);
	E=FFT(e);
	
	for(int k=0;k<N/2;++k)D[k]=D[k]*fromPolar(1,-2*M_PI*k/N);
	
	for(int k=0;k<N/2;++k){
		X[k]=E[k]+D[k];
		X[k+N/2]=E[k]-D[k];
	}
	
	return X;
}

/////////////////////////////
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int numOfSig = 5;
	compositeSignal sig1(numOfSig);
	cout<<"^{\"type\":\"data\",\"name\":\"Signal\",\"obj\":[[";
	for(int i=0;i<200;++i)cout<<"\""<<sig1.getVal(i)<<"\" , ";
	cout<<"\""<<sig1.getVal(200)<<"\" ]]} "<<endl;
	
	///////////////////////////////////
	
	
	
	double samplingRate = 1.0/(10*sig1.minFreq);
	
   	int size, i;
	size = 1/samplingRate;

	
	vector<Complex> arg(size);
	vector<Complex> result(size), result1(size);
	double frequencyX[size], amplitudeY[size];
	
	int xi, yi;
	
	for(i=0;i<size;i++)
	{
		arg[i] = sig1.getVal((i+1)*samplingRate);
		double j = arg[i].real;
		
   	}
   	vector<Complex> fft=FFT(arg);
   	cout<<"^{\"type\":\"data\",\"name\":\"FFT\",\"obj\":[[";
	for(int i=0;i<size-1;++i)cout<<"\""<<fft[i].magnitude()<<"\" , ";
	cout<<"\""<<fft[size-1].magnitude()<<"\" ]]} "<<endl;
	//testing FFT
	/*bool inverse = false;

	FFT(size, arg, result);
	//IFFT(size,result1,result);
	int x= 0,y=0;
	double freq = sig1.lcmVal;
	for(i=0;i<size;i++)
	{
		//freq = i*fr/size;
//		if(i%100==0)
		frequencyX[i] = i;
		amplitudeY[i] = abs(result[i]);
	}
	
	*/
	
	
	
	
	///////////////////
	
	return 0;
}

