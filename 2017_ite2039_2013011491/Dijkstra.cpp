//2013011491_¾ÈÂù¿µ_508 

#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct edg{
	int toV;
	int degree;
}edge;

typedef struct vertex{
	int id;
	int adj_num;
	int degree;
	int color;
	edge *edges;
	
}vertex;

vertex * nodes;
int n;

int extract_min(){
	int i, j;
	int min = -1;
	for(i = 1; i <= n; i++){
		if(nodes[i].color == GRAY){
			min = i;
			break;
		}
	}
	if(i > n){
		return -1;
	}
	for(j = i; j <= n; j++){
		if(nodes[j].color == GRAY && nodes[j].degree < nodes[min].degree){
			min = j;
		}
	}
	return min;
}



int main(){

	int i, j;
	int min;

	scanf("%d",&n);
	nodes = (vertex*)malloc(sizeof(vertex) * (n + 1));


	for(i = 1; i <= n; i++){
		scanf("%d %d", &nodes[i].id, &nodes[i].adj_num);
		nodes[i].edges = (edge *)malloc(sizeof(edge) * nodes[i].adj_num);
		for(j = 0; j < nodes[i].adj_num; j++){
			scanf("%d %d",&(nodes[i].edges[j]).toV,&(nodes[i].edges[j]).degree);			
		}
	}
	
	nodes[1].degree = 0;
	nodes[1].color = GRAY;
	
	for(i = 2; i <= n; i++){
		nodes[i].degree = -1;
		nodes[i].color = WHITE;
	}
	
	while((min = extract_min()) != -1){
		nodes[min].color = BLACK;
		for(i = 0; i < nodes[min].adj_num; i++){
			if(nodes[(nodes[min].edges[i]).toV].degree == -1){
				nodes[(nodes[min].edges[i]).toV].degree = nodes[min].degree + (nodes[min].edges[i]).degree;
				nodes[(nodes[min].edges[i]).toV].color = GRAY;
			}else if(nodes[(nodes[min].edges[i]).toV].degree > nodes[min].degree + (nodes[min].edges[i]).degree){
				nodes[(nodes[min].edges[i]).toV].degree = nodes[min].degree +(
				nodes[min].edges[i]).degree;
				nodes[(nodes[min].edges[i]).toV].color = GRAY;
			}
		}
	}
	min =0;
	for(i = 1; i <= n; i++){
		if(min < nodes[i].degree){
			min = nodes[i].degree;
		}
	}

	printf("%d\n",min);

	return 0;

}

