#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
bool debug=false;
class Solver{
    int wMax;
    vector<int> previous,wArr,contains;
	vector<long long int> lookup;
    //vector<deque <int> > contains;
    int getHCF(int a , int b){
        //if(debug)cout<<"Getting hcf of "<<a<<","<<b<<endl;
        if(b<a){//swap a and b
            a=a^b;b=a^b;a=a^b;
        }
        if(a==0)  return b;
        if(b%a==0)return a;
        else return getHCF(b,b%a);
    }
    void reduce(){
        int hcf=getHCF(wMax,wArr[0]);
        for(int i=1;i<9;++i){
            hcf=getHCF(hcf,wArr[i]);
        }
        if(debug)cout<<"HCF:"<<hcf<<endl;
        for(int i=0;i<9;++i){
            wArr[i]=wArr[i]/hcf;
            if(debug)cout<<"\twArr["<<i<<"]:"<<wArr[i]<<endl;
        }
        wMax=wMax/hcf;
    }
    void init(){
        /*int max=max_element(wArr.begin(),wArr.end());
        previous = vector<int>(2*max,-1);
        contains = vector<deque<int> >(2*max);*/
        previous = vector<int>(wMax+1,-1);
        contains = vector<int>(wMax+1,-1);
        lookup   = vector<long long int>(wMax+1,0);
    }
    void printNum(){
        deque<int> num;
        int index=wMax;
        while(index>=0){
            num.push_back(contains[index]);
            index=previous[index];
        }
        if(num.size()==1){
            printf("-1\n");
            return;
        }
        //sort(num.begin(),num.end());
        for(int i=num.size()-2;i>=0;--i){
            printf("%d",num[i]+1);
        }
        printf("\n");
    }
public:
    Solver():
    wArr(vector<int>(9))
    {
        scanf("%d",&wMax);if(debug)cout<<"Read wMax:"<<wMax<<endl;
        for(int i=0;i<9;++i){
            scanf("%d",&wArr[i]);
            if(debug)cout<<"\twArr["<<i<<"]:"<<wArr[i]<<endl;
        }
        reduce();
    }
    void solve(){
        init();
        int maxIndex=-1,n=-1;
		long long int val,max;
        /*if(debug){
			cout<<endl;
			cout<<"\tlookup["<<0<<"]:"<<lookup[0]<<endl;
			cout<<"\tcontains["<<0<<"]:"<<contains[0]+1<<endl;
			cout<<"\tprevious["<<0<<"]:"<<previous[0]<<endl;
			cout<<endl;
        }*/
        for(int i=1;i<=wMax;++i){
            max=-1;
            for(int j=0;j<9;++j)if(i-wArr[j]>=0){
                val=lookup[i-wArr[j]]*5+(j+1);
                //if(debug)cout<<" "<<val<<"("<<i-wArr[j]<<")"<<" ";
                if(max<val){
                    max=val;
                    maxIndex=i-wArr[j];
                    n=j;
                }
            }
            lookup[i]=max;
            contains[i]=n;
            previous[i]=maxIndex;
            if(debug && max!=-1 && i%10000==0){
                cout<<endl;
                cout<<"\tlookup["<<i<<"]:"<<lookup[i]<<endl;
                cout<<"\tcontains["<<i<<"]:"<<contains[i]+1<<endl;
                cout<<"\tprevious["<<i<<"]:"<<previous[i]<<endl;
                cout<<endl;
            }
        }
        printNum();
    }
};
int main(int argc , char **argv)
{
    if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
    int t;scanf("%d",&t);
    while(t){
        Solver s;
        s.solve();
        --t;
    }
    return 0;
}