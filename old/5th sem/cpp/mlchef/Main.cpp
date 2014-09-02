#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
struct Chef{
	int superior;
	queue<int> inferiorQ;
	long long int health;
	bool isOld;
	int oldCount;
	
	Chef():
	isOld(true),
	oldCount(0)
	{}
};
int n;
vector<Chef> chefArr;
void printChefArr(){
	printf("\n");
	for(int i=0;i<n+1;i++){
		printf("#%d :\n\tsuperior:%d\n\t inferiorCount:%d\n\thealth:%lld\n\toldCount:%d\n\t",i,chefArr[i].superior,chefArr[i].inferiorQ.size(),chefArr[i].health,chefArr[i].oldCount);
		if(chefArr[i].isOld)printf("Old\n");
		else printf("New\n");
	}
	printf("\n");
}
void killChef(int index , int x){
	queue<int> q=chefArr[index].inferiorQ,tempQ;
	int temp;
	while(!q.empty()){
		chefArr[q.front()].health-=x;
		if(chefArr[q.front()].isOld && chefArr[q.front()].health<=0){
			chefArr[q.front()].isOld=false;
			temp=q.front();
			do{
				temp=chefArr[temp].superior;
				chefArr[temp].oldCount--;
			}while(temp!=0);
		}
		tempQ=chefArr[q.front()].inferiorQ;
		q.pop();
		while(!tempQ.empty()){
			if(chefArr[tempQ.front()].isOld)q.push(tempQ.front());
			tempQ.pop();
		}
	}
}
int main()
{
	scanf("%d",&n);
	chefArr=vector<Chef>(n+1);
	int temp;
	for(int i=1;i<n+1;i++){
		scanf("%d %lld",&chefArr[i].health,&chefArr[i].superior);
		chefArr[chefArr[i].superior].inferiorQ.push(i);
		temp=i;
		do{
			temp=chefArr[temp].superior;
			chefArr[temp].oldCount++;
		}while(temp!=0);
	}
	//printChefArr();
	int q;scanf("%d",&q);
	int type,a,x;
	for(int i=0;i<q;i++){
		scanf("%d",&type);
		switch(type){
		case 1:
			scanf("%d %d",&a,&x);
			killChef(a,x);
			break;
		case 2:
			scanf("%d",&a);
			printf("%d\n",chefArr[a].oldCount);
			break;
		}
		//printChefArr();
	}
	return 0;
}
