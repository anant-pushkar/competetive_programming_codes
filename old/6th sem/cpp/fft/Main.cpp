/*
Project name : fft
Created on : Fri Jan 24 18:38:18 2014
Author : Anant Pushkar
test project to implement fast fourier transform
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
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
bool compare(const Complex &c1 , const Complex &c2){
	return c1.phase()<c2.phase();
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	cin>>n;
	vector<Complex> coef(n);
	for(int i=0;i<n;++i)cin>>coef[i].real;
	vector<Complex> fft=FFT(coef);
	//sort(fft.begin(),fft.end(),compare);
	cout<<"^{\"type\":\"data\",\"name\":\"fft graph\",\"obj\":[[";
	for(int i=0;i<n-1;++i)cout<<"\""<<fft[i].magnitude()<<"\",";
	cout<<"\""<<fft[n-1].magnitude();
	cout<<"\"],["<<endl;
	for(int i=0;i<n-1;++i)cout<<"\""<<(fft[i].magnitude()==0?0:fft[i].phase())<<"\",";
	cout<<"\""<<(fft[n-1].magnitude()==0?0:fft[n-1].phase());
	cout<<"\"]]}"<<endl;
	for(int i=0;i<n;++i)cout<<fft[i].toString()<<" ";
	cout<<endl;
	return 0;
}

