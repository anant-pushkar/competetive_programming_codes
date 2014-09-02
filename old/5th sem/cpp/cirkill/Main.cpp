#include<iostream>
#include<vector>
#include<utility>
using namespace std;
pair<double,double> getCircumCenter(pair<double,double> p1 , pair<double,double> p2 , pair<double,double> p3)
{
	double A = (p3.first-p2.first)/(p2.second-p3.second);
	double B =-(p3.first-p2.first)*(p2.first+p3.first)/(2*(p2.second-p3.second)) + (p2.second+p3.second)/2;
	double C = (p2.first-p1.first)/(p1.second-p2.second);
	double D =-(p2.first-p1.first)*(p1.first+p2.first)/(2*(p1.second-p2.second)) + (p1.second+p2.second)/2;
	
	double x = (B-D)/(C-A);
	double y = (B*C-A*D)/(C-A);
	
	return make_pair(x,y);
}
inline int sqDist(pair<double,double> p1 , pair<double,double>p2)
{
	return (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
}
double calc(vector< pair<int,int> > points)
{
	int count=0,baseCount=0;
	pair<double,double> circumCenter;
	for(int i=0;i<points.size()-2;i++)
	{
		for(int j=i+1;j<points.size()-1;j++)
		{
			for(int k=j+1;k<points.size();k++)
			{
				circumCenter   = getCircumCenter(points[i],points[j],points[k]);
				for(int l=0;l<points.size();l++)
				{
					if(l!=k && l!=j && l!=i)
					{
						if(sqDist(points[l],circumCenter)<=sqDist(points[i],circumCenter))
							count++;
						baseCount++;
					}
				}
			}
		}
	}
	return static_cast<double>(count/3)/(baseCount);
}
int main()
{
	int T , N;
	vector< pair<int,int> > points;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>N;
		points.clear();points=vector< pair<int,int> >(N,make_pair(0,0));
		for(int n=0;n<N;n++)
			cin>>points[n].first>>points[n].second;
		cout<<calc(points)<<endl;
	}
	return 0;
}
