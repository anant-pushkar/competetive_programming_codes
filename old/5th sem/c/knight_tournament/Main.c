#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int getPow2(int n){
	if(n&(n-1)==0)return n;
	int p=1;
	while(n!=0){
		p=p<<1;
		n=n>>1;
	}
	return p;
}
typedef struct{
	int left,right,val,flag;
}Node;
Node *arr;
int n , m , size;
void setBoundary(int index , int left , int right){
	arr[index].left = left;
	arr[index].right= right;
	
	if(left==right) return;
	
	int mid = (left+right)/2;
	setBoundary(2*index+1,left,mid);
	setBoundary(2*index+2,mid+1,right);
}
Node* init(){
	size=2*getPow2(n)-1;
	arr = (Node*)calloc(size,sizeof(Node));
	setBoundary(0,1,n);
}
void conquer(int index , int left , int right , int x){
	if(debug)printf("conquer called on index=%d(%d,%d)|%d,x=%d with left=%d,right=%d\n",index,arr[index].left,arr[index].right,arr[index].flag,left,right,x);
	if(left>right || index<0 || index>=size  || arr[index].flag == 1 || arr[index].left > left || arr[index].right < right){
		if(debug)printf("returning \n\n");
		return ;
	}
	if(arr[index].left ==left && arr[index].right ==right){
		if(debug)printf("setting up flag\n\n");
		arr[index].val  = x;
		arr[index].flag = 1;
		return ;
	}
	
	int mid = (arr[index].left+arr[index].right)/2;
	if(right <= mid){
		conquer(2*index+1 , left , right , x);
		return;
	}
	if(left > mid){
		conquer(2*index+2 , left , right , x);
		return;
	}
	conquer(2*index+1 , left  ,  mid  , x);
	conquer(2*index+2 , mid+1 , right , x);
}
void relax(int index , int val){
	if(index>size)return;
	if(debug)printf("relax called on %d(%d,%d)|%d with %d\n",index,arr[index].left,arr[index].right,arr[index].flag,val);
	if(arr[index].left == arr[index].right){
		if(arr[index].flag==0){
			arr[index].val = val!=-1 ? val : 0 ;
			if(debug)printf("Relaxing %d to %d\n",index,arr[index].val);
			arr[index].flag=0;
		}else{
			if(debug)printf("flag set at 1:%d\n",arr[index].val);
		}
		return;
	}
	if(arr[index].flag) val=arr[index].val;
	relax(2*index+1,val);
	relax(2*index+2,val);
}
void print(){
	relax(0,-1);
	int i=0,index=0;
	int *soln=(int*)calloc(n,sizeof(int));
	for(;i<size;++i)if(arr[i].left==arr[i].right && arr[i].right<=n && arr[i].right!=0){
		soln[arr[i].right-1] = arr[i].val;
		if(debug)printf("%d:%d\n",arr[i].right,arr[i].val);
		++index;
		if(index>=n)break;
	}
	for(i=0;i<n;++i){
		printf("%d ",soln[i]);
	}
}
void solve(){
	int l , r , x , i;
	scanf("%d %d",&n,&m);
	init();
	while(m--){
		scanf("%d %d %d",&l,&r,&x);
		conquer(0,l,x-1,x);
		conquer(0,x+1,r,x);
	}
	print();
	printf("\n");
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
