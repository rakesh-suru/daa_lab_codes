#include<stdio.h>
#include<stdlib.h>
#define MAX 100


int adjacencyMatrix[MAX][MAX];
int status[MAX];
int n;

void DFS(int start){
	int stack[MAX], top = -1;
	for(int i = 0; i<n; i++){
		status[i] = 1;
	}
	stack[++top] = start;
	status[start] = 2;
	
	while(top != -1){
		int node = stack[top--];
		status[node] = 3;
		for(int i = 0; i<n; i++){
			if( adjacencyMatrix[node][i] == 1 && status[i] == 1){
				stack[++top] = i;
				status[i] = 2;
			}
		}
	}
}

int isConnected(){
	DFS(0);
	for(int i = 0; i<n; i++){
		if(status[i] != 3){
		return 0;
		}
	}
	return 1;
}

int main(){
	int edges, u, v;
	
	printf("Enter number of Nodes :");
	scanf("%d", &n);
	printf("Enter number of Edges :");
	scanf("%d", &edges);
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			adjacencyMatrix[i][j] = 0;
		}
	}
	
	printf("Enter edges (format : from to) :\n");
	for(int i = 0; i<edges; i++){
		scanf("%d%d", &u, &v);
		adjacencyMatrix[u][v] = 1;
		adjacencyMatrix[v][u] = 1;
	}
	
	if(isConnected()){
		printf("The Graph is Connected\n");
	}
	else{
		printf("The Graph is not Connected\n");
	}
	return 0;
}
