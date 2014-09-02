#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;
bool debug=false;
class Solver{
	set<string> forbidden;
	string start,end;
	/*string next(string present , vector<int> control){
		char c[3];
		//if(debug)cout<<present<<"->";
		for(int i=0;i<4;++i){
			sprintf(c,"%d",(present[i]-'0'+control[i]+10)%10);
			present[i]=c[0];
		}
		//if(debug)cout<<present<<endl;
		return present;
	}
	inline bool isForbidden(string str){
		return forbidden.find(str)!=forbidden.end();
	}*/
	int viablePath(int index){
		
	}
public:
	Solver():
	start("####"),
	end("####"){
		scanf("\n%c %c %c %c",&start[0],&start[1],&start[2],&start[3]);
		scanf("\n%c %c %c %c", &end[0] , &end[1] , &end[2] , &end[3] );
		int n;scanf("%d\n",&n);
		string temp("####");
		while(n){
			scanf("%c %c %c %c\n", &temp[0] , &temp[1] , &temp[2] , &temp[3] );
			if(debug)cout<<"Adding |"<<temp<<"| to forbidden list"<<endl;
			forbidden.insert(temp);
			//char c;scanf("%c\n",&c);
			--n;
		}
		if(debug){
			cout<<"Start :|"<<start<<"|"<<endl;
			cout<<"End : |"<<end<<"|"<<endl;
		}
	}
	int solve(){
		
	}
	/*int solve(){
		queue<string> q;
		queue<int> count;
		vector<int> control;
		
		q.push(start);count.push(0);
		string present,nextStr;
		int n;
		for(int a=0;a<10000;++a){
			present=q.front();q.pop();
			n=count.front();count.pop();
			if(debug)cout<<"At |"<<present<<"| : "<<n<<endl;
			if(present==end)break;
			for(int i=0;i<4;++i){
				control=vector<int>(4,0);
				
				control[i]=1;
				nextStr=next(present,control);
				if(!isForbidden(nextStr)){
					//if(debug)cout<<"Pushing "<<nextStr<<" to queue"<<endl;
					q.push(nextStr);count.push(n+1);
				}
				
				control[i]=-1;
				nextStr=next(present,control);
				if(!isForbidden(nextStr)){
					//if(debug)cout<<"Pushing "<<nextStr<<" to queue"<<endl;
					q.push(nextStr);count.push(n+1);
				}
			}
			if(debug)cout<<endl;
		}
		if(present==end)return n;
		else return -1;
	}*/
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t){
		Solver s;
		printf("%d\n",s.solve());
		--t;
		scanf("\n");
	}
	return 0;
}

