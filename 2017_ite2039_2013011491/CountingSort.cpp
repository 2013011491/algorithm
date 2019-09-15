//2013011491_¾ÈÂù¿µ_508 


#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define TREE_EDGE 1
#define BACK_EDGE 2
#define FORWARD_EDGE 3
#define CROSS_EDGE 4

#define TRUE 1
#define FALSE 0
typedef struct edge{
	int edge;
	int weight;
}edge;
typedef struct _vertex{
	int color;
	int f;
	int d;
	int out_degree;
	edge list[5001];
}Vertex;


Vertex vertex[1001];
int numV, time;
int * topoList;
int topo_num = 0;
int isDAG = TRUE;

void addEdge(int fromV, int toV){
	int i = 0;
	int cur = 0;

	for(i = 0; i < numV; i++){
		if(vertex[fromV].list[i] == 0){
			break;
		}
		cur ++;
	}
	vertex[fromV].list[cur] = toV;
}

void DFS_visit(int fromV){
	int i = 0, toV;

	time++;

	vertex[fromV].color = GRAY;
	vertex[fromV].d = time;

	for(i = 0; i < vertex[fromV].out_degree; i++){
		toV = vertex[fromV].list[i];
		switch(vertex[toV].color){
			case WHITE:
				DFS_visit(toV);
				break;
			case GRAY:
				isDAG = FALSE;
				break;
			case BLACK:
				break;
			default:
				break;
		}
	}
	vertex[fromV].color = BLACK;
	topoList[numV - (topo_num++)] = fromV;
	time ++;
	vertex[fromV].f = time;
}

void Sort(int * list, int num){
	int i,j,tmp;

	for(i = 0; i < num; i++){
		for(j = i + 1; j < num; j++){
			if(list[i] > list[j]){
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void DFS(void){
	int i;

	for(i = 1; i <= numV; i++){
		vertex[i].d = 0;
		vertex[i].f = 0;
		vertex[i].color = WHITE;
		Sort(vertex[i].list, vertex[i].out_degree);
	}
	time = 0;
	for(i = 1; i <= numV; i++){
		if(vertex[i].color == WHITE){
			DFS_visit(i);
		}
	}
}

int main(){
	int i, j;
	int fromV, toV;

	scanf("%d", &numV);

	
	for(i = 1;i <= numV; i++){
		vertex[i].out_degree = 0;
	}

	for(i = 1; i <= numV; i++){
		for(j = 0; j < numV; j++){
			vertex[i].list[j] = 0;
		}
	}

	topoList = (int *)malloc(sizeof(int) * (numV + 1));

	while(scanf("%d %d", &fromV, &toV) != EOF){
		addEdge(fromV, toV);
		vertex[fromV].out_degree++;
	}
	DFS();

	printf("%d\n", isDAG);
	if(isDAG){
		for(i = 1; i <= numV; i++){
			printf("%d ",topoList[i]);
		}
	}
	return 0;
}

