#include"graph.h"
void print_vector(igraph_vector_t *v, FILE *f) {
  long int i;
  for (i=0; i<igraph_vector_size(v)-1; i+=2) {
    fprintf(f, "[\"%li\" , \"%li\" , \"\"] , ", (long int) VECTOR(*v)[i],(long int) VECTOR(*v)[i+1]);
  }
  fprintf(f, "[\"%li\" , \"%li\" , \"\"] ", (long int) VECTOR(*v)[igraph_vector_size(v)-2],(long int) VECTOR(*v)[igraph_vector_size(v)-1]);
  fprintf(f, "\n");
}
void print_graph(igraph_t* graph){
	//printf("creating vector\n");
	igraph_vector_t v;
	
	//printf("getting edgelist\n");
	igraph_get_edgelist(graph, &v, 0);
	
	//printf("printing  vector\n");
	printf("^{	\"type\":\"graph\",	\"name\" : \"test Graph\",	\"obj\":[");
	print_vector(&v, stdout);
	printf("]}\n");
}
void create_adj_mat(){
	igraph_spmatrix_init(&adjMat, nVertices, nVertices);
	igraph_get_adjacency_sparse(&g, &adjMat, 0);
	int i;
	for(i=0;i<nVertices;++i){
		igraph_spmatrix_add_e(&adjMat, i, i,1);
	}
	//igraph_spmatrix_print(&adjMat);
}
void create_graph(){
	scanf("%d %d",&nVertices , &nEdges);
	int i,a,b;
	igraph_vector_t v;
	igraph_vector_init (&v, 2*nEdges);
	for(i=0;i<2*nEdges;i+=2){
		scanf("%d %d",&a,&b);
		if(a>nVertices || b>nVertices){
			printf("vertex id overflow : %d-%d\n",a,b);
			break;
		}
		VECTOR(v)[i]=a;
		VECTOR(v)[i+1]=b;
	}
	igraph_create(&g, &v, 0, 1);
	create_adj_mat();
}
void create_from_file(){
	FILE *ifile=fopen("LINKS.NET", "r");
	if (ifile==0) {
		perror("Could not open input file");
	}
	//printf("creating graph\n");
	igraph_read_graph_pajek(&g, ifile);
	fclose(ifile);
	//printf("graph created\n");
}
