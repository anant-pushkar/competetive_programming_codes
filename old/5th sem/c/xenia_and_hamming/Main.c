#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_MAX_LEN 1000000
int debug=0;
typedef long long int lld;
lld getHamming(char *str1 , char *str2 , int size1 , int size2){
	int n , m , i=0 , j;
	lld dist=0;
	for(;i<size1;++i){
		j=i;n=0;
		for(;n<size2;++n){
			if(str1[i]==str2[j])++dist;
			j=(j+size1)%size2;
		}
	}
}
void solve(){
	lld n , m ,x_size,y_size;
	scanf("%lld %lld",&n,&m);
	
	x_size = n>STR_MAX_LEN ? STR_MAX_LEN : n;
	y_size = m>STR_MAX_LEN ? STR_MAX_LEN : m;
	
	char * x = (char*)calloc(x_size+1 , sizeof(char)) , y = (char*)calloc(y_size+1 , sizeof(char));
	scanf("%s",x);scanf("%s",y);
	
	printf("%lld\n",getHamming(x,y,strlen(x),strlen(y)));
	
	free(x);
	free(y);
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
