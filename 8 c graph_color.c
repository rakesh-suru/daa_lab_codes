#include<stdio.h>
#include<stdbool.h>
#define V 4

bool isSafe(int v, bool graph[V][V], int color[], int c){
	int i;
	for(i = 0; i < V; i++){
		if(graph[v][i] && color[i] == c){
			return false;
		}
	}
	return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v){
	if(v == V){
		return true;
	}
	
	int c;
	for(c = 1; c <= m; c++){	
		if(isSafe(v, graph, color, c)){
			color[v] = c;
			if(graphColoringUtil(graph, m, color, v + 1)){
				return true;
			}
			color[v] = 0;
		}
	}
	return false;
}

void printSolution(int color[]){	
	printf("Solution Exists, Assigned Colors :\n");
	int i;
	for(i = 0; i < V; i++){
		printf("Vertex %d --> Color %d\n", i, color[i]);
	}
}

void graphColoring(bool graph[V][V], int m){
	int color[V] = {0};
	if(!graphColoringUtil(graph, m, color, 0)){
		printf("Solution does not exist\n");
		return;
	}
	printSolution(color);
}

int main(){
	bool graph[V][V] = {
		{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0}
	};
	int m =3;
	graphColoring(graph, m);
	return 0;
}
		