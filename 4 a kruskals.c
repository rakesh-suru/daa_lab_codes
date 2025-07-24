//kruskals algorithm to find minimum cost spanning tree

#include<stdio.h>
#define MAX 30

typedef struct{
	int u, v, w;
}Edge;

Edge edges[MAX], result[MAX];
int parent[MAX];
int n, e;

int find(int i){
	while(parent[i] != i){
		i = parent[i];
	}
	return i;
}

void union_set(int i, int j){
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void sort_edges(){
	int i, j;
	Edge temp;
	
	for(i = 0; i < e-1; i++){
		for(j = i+1; j < e; j++){
			if(edges[i].w > edges[j].w){
				temp  = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}
}

void kruskals(){
	int i,j = 0;
	int total_cost = 0;
	sort_edges();
	
	for(i = 0; i<n; i++){
		parent[i] = i;
	}
	
	for(i = 0; i < e; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		
		if (find(u) != find(v)){
			result[j++] = edges[i];
			total_cost += w;
			union_set(u, v);
		}
	}
	
	printf("Edges in Minimum Spanning Tree : \n");
	for(i = 0; i< j; i++){
		printf("%d -- %d = %d\n", result[i].u, result[i].v, result[i].w);
	}
	printf("Total Cost of MST = %d\n", total_cost);
}

int main(){
	int i;
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	
	printf("Enter number of edges: ");
	scanf("%d", &e);

	printf("Enter edges (u v w) :\n");
	for(i = 0; i < e; i++){
		scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	
	kruskals();
	return 0;
}