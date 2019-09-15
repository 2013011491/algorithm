//2013011491_¾ÈÂù¿µ_508
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int count=0;
int n;

typedef struct vertex{
	int color;
	int component;
	int data;
	struct vertex *adjance;
}; 

void vertexinit(vertex *graph,int n){
	int i;
	for(i=1; i<=n; i++){
		graph[i].color=WHITE;
		graph[i].component=1;
		graph[i].data=i;
		graph[i].adjance=NULL;
	}
}

vertex *create_node(int data)
{
vertex *new_node;
new_node = (vertex *)malloc(sizeof(vertex));
new_node->data = data;
new_node->adjance = NULL;
return (new_node);
}

void insertlist(vertex *graph,int st, vertex *new_node){
	vertex *temp1=&graph[st];
	
	if(graph[st].adjance==NULL){
		graph[st].adjance=new_node;
		return;
	}
	while(1){
	if((*temp1).adjance==NULL){
		(*temp1).adjance=new_node;
		return;
	}else{
		temp1=(*temp1).adjance;
	}}
	
}

void dfs_visit(vertex *graph,int u){
	int v;
	vertex *temp=&graph[u]; 
	graph[u].color=GRAY;
	while((*temp).adjance!=NULL){
		*temp=*temp->adjance;
		if(graph[(*temp).data].color==WHITE){
			dfs_visit(graph,(*temp).data);
		}
	}
	graph[u].color=BLACK;
	graph[u].component=count;
}


void dfs_mod(vertex *graph,int n){
	int u;
	 for(u=1;u<=n;u++){
	        if(graph[u].color==WHITE){
			count++;
			dfs_visit(graph,u);
		}
	}
	
	
}

int main(){
	int st,fi;
	int i,j;
	vertex graph[1001];

	
	scanf("%d",&n);
	vertexinit(graph,n);
	
	while(!feof(stdin)){
		scanf("%d %d",&st,&fi);
		insertlist(graph,st,create_node(fi));
		insertlist(graph,fi,create_node(st));
		
}
	dfs_mod(graph,n);
	printf("%d\n",count);
	for(i=1; i<=n;i++){
		printf("%d\n",graph[i].component);
	}
	
	return 0;
}

