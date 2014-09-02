#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
class Solver{
	vector<int> h, d;
	int d_sum,iter_count;
	void activate(vector<int> &v,int index,int delta){
		v[index]-=delta;
		for(int i=0;i<v.size();++i)if(i!=index){
			v[i]+=delta;
		}
	}
	bool check(const vector<int> &v){
		for(int i=0;i<d.size();++i){
			if(v[i]!=d[i])return false;
		}
		return true;
	}
	/*int recurse(vector<int> v , int count){
		if(check(v)) return count;
		if(count>iter_count) return -1;
		int delta,n,min=iter_count+2;
		for(int i=0;i<v.size();++i){
			delta=d[i]-v[i];delta=delta>0?delta:-delta;
			if(delta>iter_count-count) return -1;
			activate(v,i,1);
			n=recurse(v,count+1);
			if(n!=-1)min = n<min ? n : min;
			activate(v,i,-1);
		}
		return min==iter_count+2?-1:min;
	}*/
public:
	Solver(int n):
	h(vector<int>(n)),
	d(vector<int>(n)),
	d_sum(0)
	{
		int sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&h[i]);
			sum+=h[i];
		}
		for(int i=0;i<n;++i){
			scanf("%d",&d[i]);
			d_sum+=d[i];
		}
		iter_count=d_sum-sum;
	}
	void solve(){
		if(h.size()==1){
			if(h[0]<d[0]) printf("-1\n");
			else printf("%d\n",(h[0]-d[0]));
			//printf("-1\n");
			return;
		}
		if(h.size()==2){
			if(iter_count!=0)printf("-1\n");
			else{
				int diff=h[0]-d[0];diff=diff>0?diff:-diff;
				printf("%d\n",diff);
			}
			return;
		}
		if(iter_count>=0 && iter_count%(h.size()-2)==0){
			int count=iter_count/(h.size()-2);
			for(int i=0;i<h.size();++i){
				if(count-d[i]+h[i]<0 || count+d[i]-h[i]<0 || (count+d[i]-h[i])%2!=0){
					printf("-1\n");
					return;
				}
			}
			vector<int> lo(h.size()),hi(h.size());
			int n=0;
			for(int i=0;i<h.size();++i){
				hi[i]=(count+d[i]-h[i])/2;
				lo[i]=(count-d[i]+h[i])/2;
				n+=lo[i];
			}
			int h_min=*min_element(hi.begin(),hi.end());
			int l_max=*max_element(lo.begin(),lo.end());
			if(debug)cout<<"h_min:"<<h_min<<" l_max:"<<l_max<<endl;
			for(int i=0;i<h.size();++i){
				h[i]-=lo[i];
				for(int j=0;j<h.size();++j){
					if(i!=j){
						h[j]+=lo[i];
					}
					if(debug)cout<<h[j]<<" ";
				}
				if(debug)cout<<endl;
			}
			if(check(h) && n==count)printf("%d\n",count);
			else printf("-1\n");
		}
		else printf("-1\n");
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;scanf("%d",&t);
	while(t){
		scanf("%d",&n);
		Solver s(n);
		s.solve();
		--t;
	}
	return 0;
}

