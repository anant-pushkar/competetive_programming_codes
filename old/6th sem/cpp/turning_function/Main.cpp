/*
Project name : turning_function
Created on : Wed Mar 19 23:07:14 2014
Author : Anant Pushkar
module to  get turning function of a polygon
input format : 
n
x0 y0
x1 y1
. . .
. . . 
x{n-1} y{n-1}

x{i} y{i} being ith point
n is the number of points

pipe to filter.py to plot graphs
To install dependenies for plotter:
sudo apt-get install python-networkx
sudo apt-get install python-matplotlib

To test using interpolation install gsl library and #define GSL

*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<map>
#include<map>
#include<set>
#include<queue>
#define _USE_MATH_DEFINES
#ifdef GSL
#include<gsl/gsl_errno.h>
#include<gsl/gsl_spline.h>
#endif
using namespace std;
bool debug=false;
inline int dot_product(const pair<int,int> &p1 , const pair<int,int> &p2 , const pair<int,int> &p3){
	return (p2.first-p1.first)*(p3.first-p2.first) + (p2.second-p1.second)*(p3.second-p2.second);
}
inline double mod(const pair<int,int> &p1 , const pair<int,int> &p2){
	return (p2.first-p1.first)*(p2.first-p1.first) + (p2.second-p1.second)*(p2.second-p1.second);
}
inline double magnitude(const pair<int,int> &p1 , const pair<int,int> &p2 , const pair<int,int> &p3){
	double m1= mod(p1,p2) , m2=mod(p2,p3);
	return sqrt(m1)*sqrt(m2);
}
//needed to check if the polygon turned in -ve or +ve direction
inline int get_direction(const pair<int,int> &p1 , const pair<int,int> &p2 , const pair<int,int> &p3){
	int direction=(p1.first-p2.first)*(p3.second-p2.second)-(p3.first-p2.first)*(p1.second-p2.second);
	return direction>0 ? -1 : 1;
}
inline double get_angle(const pair<int,int> &p1 , const pair<int,int> &p2 , const pair<int,int> &p3){
	return get_direction(p1,p2,p3)*acos(dot_product(p1,p2,p3)/magnitude(p1,p2,p3));
}
vector<pair<double,double> > get_turning_function(const vector<pair<int,int> > &polygon){
	int n=polygon.size();
	vector<pair<double,double> > func(n);
	pair<int,int> p1=polygon[n-1] , p2=polygon[0] , p3=polygon[1] ;
	double d=mod(p1,p2);
	func[0]=make_pair(d,get_angle(p1,p2,p3));

	for(int i=1;i<n;++i){
		p1=p2;p2=p3;p3=polygon[(i+1)%n];
		d=d+mod(p2,p3);
		func[i]= make_pair(d,get_angle(p1,p2,p3));
	}
	return func;
}
struct histopoints
{
   map<int,int> histo;
   map<int,set<int> > points;
};

vector<double> diff(vector<double> a,vector<double> b, int d) //calculates the difference between two curves
{
   int m = a.size();
   int n = b.size();
   vector<double> ret;
   int sz = b.size();
   for(int i = 0;i<sz;i++)
   {
       ret.push_back(a[(i+d)%sz]-b[i]);
   }
   return ret;
}

histopoints histogram(vector<double> a, double dT)
{
   histopoints ret;
   int mult = 1/dT;
   int sz = a.size();
   for(int i = 0;i<sz;i++)
   {
       int num = mult * a[i];
       ret.histo[num]++;
       ret.points[num].insert(i);
   }
   return ret;
}


/*
 * D : number of different values of d for which histogram must be populated (ideally should cover the whole curve)
 * th : peak threshold for histogram
 * l : minimum length of a viable match
 */
vector<pair< pair<int, int> , pair<int, int> > > getCandidateMatches(const vector<double> &turnA ,const vector<double> &turnB , int D , int th , int l , int nc)
{
	int i = 0 , m , s,e,nTurns;
	histopoints hp;
	vector<double> diff_arr;
	double dT = 0.25 , tolerence=0.05 , critical_angle=M_PI/36;
	map<int,int>::iterator histo_it;
	set<int> peak;
	set<int>::iterator sit;
	queue<pair<int,int> > q;
	queue<int> d_q;

	for(int d=0;d<D;++d){
		diff_arr = diff(turnA,turnB,d);
		m = diff_arr.size();

		hp = histogram(diff_arr,dT);

		cout<<"^{\"type\":\"data\",\"name\" : \"histogram#"<<d<<"\",\"obj\":[[";
		for(histo_it = hp.histo.begin(); histo_it != hp.histo.end();++histo_it)
		{
			if(debug)cout<<histo_it->first<<":";	
			cout<<histo_it->second<<" , ";
		}
		cout<<"0]]}"<<endl;

		if(hp.histo.begin()->second>=th){
			cout<<"Match successful.Further refinement needed"<<endl;
			for(int i=0;i<m;++i){
				s=i;nTurns=0;
				while(i<m && diff_arr[i]>-tolerence && diff_arr[i]<tolerence){
					++i;
					if(turnB[i]>critical_angle)++nTurns;
				}
				e=i;
				cout<<"Length : "<<e-s<<endl;
				cout<<"Number of sharp turns : "<<nTurns<<endl;
				if(e-s>=l && nTurns>nc){
					q.push(make_pair(s,e));
					d_q.push(d);
				}
			}
		}
	}
	vector<pair< pair<int, int> , pair<int, int> > > soln(q.size());
	int a,b;
	for(int i=0;i<soln.size();++i){
	a=q.front().first+d_q.front();a=a%turnB.size();
	b=q.front().second+d_q.front();b=b%turnB.size();
	soln[i]=make_pair(make_pair(a,b),q.front());
	d_q.pop();
	q.pop();
	}
	return soln;
	}
	/*
	* Extracts character string used for matching from turning function
	*/
	vector<double> get_str_without_interpolation(const vector<pair<double,double> > &turning_func){
	int n=turning_func.size();
	vector<double> f1(n);
	for(int i=0;i<n;++i){
	f1[i]=turning_func[i].second;
	}
	return f1;
}
/*
* Extracts character string used for matching from turning function
* Uses spline interpolation to sample turining funcion at constant interval of arc length delta
* Need to install gsl library for interpolation
*/
#ifdef GSL
vector<double> get_str_with_interpolation(const vector<pair<double,double> > &turning_func,double delta){
	int n=turning_func.size();
	gsl_interp_accel *acc = gsl_interp_accel_alloc ();
	gsl_spline *spline = gsl_spline_alloc (gsl_interp_cspline, n);

	double x[n] , y[n];
	for(int i=0;i<n;++i){
	x[i]=turning_func[i].first;
	y[i]=turning_func[i].second;
	}
	gsl_spline_init (spline, x, y, n);

	int len=x[n-1]/delta+1;
	vector<double> char_str(len);
	int index=0;
	for(double d=x[0];d<x[n-1];d+=delta){
		char_str[index++]=gsl_spline_eval (spline, d, acc);
	}
	gsl_spline_free (spline);
	gsl_interp_accel_free (acc);

	return char_str;
}
#endif
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	double delta;

	cin>>n>>delta;
	vector<pair<int,int> > polygon1=vector<pair<int,int> >(n);
	for(int i=0;i<n;++i) cin>>polygon1[i].first>>polygon1[i].second;
	vector<pair<double,double> > turning_func=get_turning_function(polygon1);
	vector<double> f1=get_str_without_interpolation(turning_func);
	/*To use Interpolation
	vector<double> f1=get_str_with_interpolation(turning_func,delta);*/

	cin>>n>>delta;
	vector<pair<int,int> > polygon2=vector<pair<int,int> >(n);
	for(int i=0;i<n;++i) cin>>polygon2[i].first>>polygon2[i].second;
	turning_func=get_turning_function(polygon2);
	vector<double> f2=get_str_without_interpolation(turning_func);
	/*To use interpolation
	vector<double> f2=get_str_with_interpolation(turning_func,delta);*/

	vector<pair< pair<int, int> , pair<int, int> > > soln = getCandidateMatches(f1,f2,10,3,1,1);
	cout<<"Soln returned : ";
	for(int i=0;i<soln.size();++i){
		cout<<"("<<soln[i].first.first<<" to "<<soln[i].first.second<<") in A"<<endl ;
		cout<<"("<<soln[i].second.first<<" to "<<soln[i].second.second<<") in B"<<endl ;
	}

	for(int i=0;i<soln.size();++i)
	{
	//transform_and_match(polygon1, polygon2, soln[i].first, soln[i].second);
	}

	return 0;
}