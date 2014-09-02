#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Task{
	int d;
	int m;
};
istream& operator>>(istream& in, Task& task)
{
    in>>task.d>>task.m;
    return in;
}
ostream& operator<<(ostream& out, Task& task)
{
    out<<"["<<task.d<<","<<task.m<<"]";
    return out;
}
bool compareD(const Task &t1 ,const Task &t2){
	return t1.d<t2.d;
}
int main() {
	int N,time,overShoot,index;
	vector<Task> taskList;
	cin>>N;
	taskList=vector<Task>(N);
	Task task;
	for(int n=0;n<N;n++) cin>>taskList[n];
	for(int n=1;n<N+1;n++){
		index=lower_bound(taskList.begin(),taskList.begin()+n,taskList[n-1],compareD)-taskList.begin();
		task=taskList[n-1];
		for(int i=n-1;i>=index+1;i--){
			taskList[i]=taskList[i-1];
		}
		taskList[index]=task;
		//cout<<"TaskList : "<<endl;
		//for(int i=0;i<n;i++) cout<<taskList[i]<<" ";
		//cout<<endl;
		time=0;overShoot=0;
		for(int i=0;i<n;i++){
			time+=taskList[i].m;
			//cout<<"TIme : "<<time<<endl;
			if(time>taskList[i].d) overShoot = time-taskList[i].d > overShoot ? time-taskList[i].d : overShoot;
		}
		//cout<<"Overshoot : "<<overShoot<<endl<<endl;
		cout<<overShoot<<endl;
	}
    return 0;
}
