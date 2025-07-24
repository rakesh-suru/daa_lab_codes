#include<stdio.h>
#include<stdbool.h>
#define V 5
int path[V];

bool isSafe(int v, int graph[V][V], int pos){
	if(graph[path[pos-1]][v] == 0){
		return false;
	}
	int i;
	for(i = 0; i < pos; i++){
		if(path[i] == v){
			return false;
		}
	}
	return true;
}

bool hamCycleUtil(int graph[V][V], int pos){
	if(pos == V){
		return graph[path[pos-1]][path[0]] == 1;
	}
	int v;
	for(v =1; v < V; v++){
		if(isSafe(v, graph, pos)){
			path[pos] = v;
			
			if(hamCycleUtil(graph, pos + 1)){
				return true;
			}
			
			path[pos] = -1;
		}
	}
	return false;
}

void printSolution(){
	printf("Hamiltonian Cycle Exists\n");
	int i;
	for(i = 0; i < V; i++){
		printf("%d\t", path[i]);
	}
	printf("%d\n", path[0]);
}

void hamCycle(int graph[V][V]){
	int i;
	for(i = 0; i < V; i++){
		path[i] = -1;
	}
	path[0] = 0;
	
	if(!hamCycleUtil(graph, 1)){
		printf("No Hamiltonian Cycle Found\n");
		return;
	}
	printSolution();
}

int main(){
	int graph[V][V] = {
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{0, 1, 1, 1, 0}
	};
	hamCycle(graph);
	return 0;
}