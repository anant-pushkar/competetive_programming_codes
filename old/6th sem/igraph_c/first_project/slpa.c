#include "slpa.h"
int ** rep;
double *maxVal;
int *freq;
int *freq_numchange;
int total_change;
int ** ss_lookup;
int is_subset(int a , int b){
	if(a>b){
		a=a^b;
		b=a^b;
		a=a^b;
	}
	//if(ss_lookup[a][b]!=-1)return ss_lookup[a][b];
	int c1=0 , c2=0 , i , j , check1=0 , check2=0;
	for(i=0;i<nVertices;++i){
		++c1;
		++c2;
		if(rep[a][i]==-1 )check1=1;
		if(rep[b][i]==-1) check2=1;
		if(check1 && check2)break;
	}
	int c = c1>c2 ? c2 : c1 , count=0;
	//for(i=0;i<nVertices;++i)if(rep[a][i]==rep[b][i])++count;
	i=0;j=0;
	while(rep[a][i]!=-1 && rep[b][j]!=-1){
		if(rep[a][i]<rep[b][j])
			while(rep[a][i]<rep[b][j]){
				++i;
				if(rep[a][i]==-1)break;
			}
		else
			 while(rep[a][i]>rep[b][j]){
			 	++j;
				 if(rep[b][j]==-1)break;
			}
		if(rep[a][i]==rep[b][j])	++count;
		else break;
		++i;++j;
	}
	if(c==count){
		//ss_lookup[a][b]=1;
		return 1;
	}
	//ss_lookup[a][b]=0;
	return 0;
}
int* get_condition(double r){
	printf("getting condition with %f\n",r);
	int *check=(int*)calloc(nVertices,sizeof(int)) , i , j;
	rep=(int**)calloc(nVertices,sizeof(int*));
	for(i=0;i<nVertices;++i)rep[i]=(int*)calloc(nVertices,sizeof(int));
	
	printf("initialising rep\n");
	int index=0;
	for(i=0;i<nVertices;++i){
		for(j=0;j<nVertices;++j)if(label_arr[i][j]==maxVal[i]){
			rep[i][j]=1;
		}
	}
	//int index;
	for(index=0;index<nVertices;++index){
		i=0;j=0;
		while(j<nVertices){
			while(rep[index][j]==0)++j;
			rep[index][i++]=j++;
		}
		rep[index][i]=-1;
	}
	
	
	
	int count;
	printf("counting\n");
	/*ss_lookup=(int**)calloc(nVertices,sizeof(int));
	for(i=0;i<nVertices;++i){
		ss_lookup[i]=(int*)calloc(nVertices,sizeof(int));
		for(j=0;j<nVertices;++j){
			ss_lookup[i][j]=-1;
		}
	}*/
	for(i=0;i<nVertices;++i){
		count=0;
		//printf("%d:\n",i);
		for(j=0;j<nVertices;++j){
			if(is_subset(i,j))++count;
		}
		if(count>r*degree[i])check[i]=1;
	}
	return check;
}
void propogate(double r){
	printf("propogating\n");
	int i,j,k,q,max;
	pre_cpy=(double**)calloc(nVertices,sizeof(double*));
	maxVal=(double*)calloc(nVertices,sizeof(double));
	printf("preparing copy\n");
	for(i=0;i<nVertices;++i){
		pre_cpy[i]=(double*)calloc(nVertices,sizeof(double));
		for(j=0;j<nVertices;++j)pre_cpy[i][j]=label_arr[i][j];
	}
	int max_degree=0;
	for(i=0;i<nVertices;++i){
		k=1;
		//printf("at %d\n",i);
		for(j=0;j<nVertices;++j)if(i!=j && igraph_spmatrix_e(&adjMat,i,j)==1){
			for(q=0;q<nVertices;++q){
				label_arr[i][q]+=label_arr[j][q];
			}
			++k;
		}
		for(j=0;j<nVertices;++j)label_arr[i][j]/=k;
		degree[i]=k;
		maxVal[i]=maxVal[i]<label_arr[i][j]?label_arr[i][j]:maxVal[i];
		max_degree=max_degree>k?max_degree:k;
	}
	
	int *check=get_condition(r);
	//printf("updating new values\n");
	for(i=0;i<nVertices;++i)if(check[i]){
		label_arr[i]=pre_cpy[i];
	}else{
		++freq[i];
		++total_change;
	}
	for(i=0;i<nVertices;++i)free(pre_cpy[i]);
	free(pre_cpy);
	free(maxVal);
	free(check);
	/*for(i=0;i<nVertices;++i)free(ss_lookup[i]);
	free(ss_lookup);
	for(i=0;i<nVertices;++i)free(rep[i]);
	free(rep);*/
}
void inflate(int r){
	//printf("inflating\n");
	int i,j;
	double sum;
	for(i=0;i<nVertices;++i){
		sum=0;
		for(j=0;j<nVertices;++j){
			label_arr[i][j]=pow(label_arr[i][j],r);
			sum+=label_arr[i][j];
		}
		for(j=0;j<nVertices;++j)label_arr[i][j]/=sum;
	}
}
void cutoff(double r){
	int i,j;
	double sum;
	for(i=0;i<nVertices;++i){
		sum=0;
		for(j=0;j<nVertices;++j){
			if(label_arr[i][j]<r){
				label_arr[i][j]=0;
			}
			sum+=label_arr[i][j];
		}
		for(j=0;j<nVertices;++j)label_arr[i][j]/=sum;
	}
}
void print_label(int index){
	printf("^{\n	\"type\":\"data\",\n	\"name\" : \"Label Distribution for %d\",\n	\"obj\":[[",index);
	int i;
	for(i=0;i<nVertices-1;++i){
		printf("\"%f\",",label_arr[index][i]);	
	}
	printf("\"%f\"",label_arr[index][nVertices-1]);
	printf("]]\n}\n");
}
void init_label(){
	label_arr=(double**)calloc(nVertices,sizeof(double*));
	int i,j;
	for(i=0;i<nVertices;++i)label_arr[i]=(double*)calloc(nVertices,sizeof(double));
	for(i=0;i<nVertices;++i)label_arr[i][i]=1;
	
	//cId=(int*)calloc(nVertices,sizeof(int));
	//for(i=0;i<nVertices;++i)cId[i]=i;
}
void print_comm(FILE *fptr){
	int *lookup=(int*)calloc(nVertices,sizeof(int));
	int i,j;
	//fprintf(fptr,"rep : ");
	//for(i=0;i<nVertices;++i)fprintf(fptr,"%d ",rep[i][0]);
	//fprintf(fptr,"\n");
	for(i=0;i<nVertices;++i)if(!lookup[i]){
		fprintf(fptr,"%d ",i);
		lookup[i]=1;
		for(j=0;j<nVertices;++j)if(i!=j && rep[i][0]==rep[j][0]){
			fprintf(fptr,"%d ",j);
			lookup[j]=1;
		}
		fprintf(fptr,"\n");
	}
}
void iterate(int n,int index,double r,double threshold,int cutoff_freq){
	int i,j,flag=0;
	init_label();
	degree=(int*)calloc(nVertices,sizeof(int));
	freq=(int*)calloc(nVertices,sizeof(int));
	freq_numchange=(int*)calloc(nVertices,sizeof(int));
	for(i=0;i<2*n;++i){
		printf("%d\n",i);
		total_change=0;
		propogate(r);
		inflate(4);
		cutoff(threshold);
		//print_label(index);
		++freq_numchange[total_change];
		if(freq_numchange[total_change]>=15)break;
		/*for(j=0;j<nVertices;++j){
			++freq_numchange[freq[j]];
			if(freq_numchange[freq[j]]>5)flag=1;
		}*/
		//printf("freq_numchange : ");
		//for(j=0;j<nVertices;++j)printf("%d ",freq_numchange[j]);
		//printf("\n");
		if(total_change==0){
			if(flag>5)break;
			else ++flag;
		}
	}
	FILE *fptr=fopen("comm.txt","w+");
	for(i=0;i<nVertices;++i){
		maxVal[i]=0;
		for(j=0;j<nVertices;++j){
			maxVal[i]=maxVal[i]<label_arr[i][j]?label_arr[i][j]:maxVal[i];
		}
	}
	//fprintf(fptr,"maxVal : ");
	for(i=0;i<nVertices;++i){
		for(j=0;j<nVertices;++j)if(label_arr[i][j]==maxVal[i]){
			rep[i][0]=j;
			break;
		}
		//fprintf(fptr,"%f ",maxVal[i]);
	}
	//fprintf(fptr,"\n");
	print_comm(fptr);
	close(fptr);
}
void free_label(){
	int i;
	for(i=0;i<nVertices;++i){
		free(label_arr[i]);	
	}
	free(label_arr);
}
