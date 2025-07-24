#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 100

void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end){
	graph[start][end] = 1;
}

void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex){
	int visited[MAX_VERTICES] = {0};
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;
	
	visited[startVertex] = 1;
	queue[rear++] = startVertex;
	printf("Nodes reachable from %d using BFS: ", startVertex);
	
	while(front != rear){
		int currentVertex = queue[front++];
		printf("%d  ", currentVertex);
		
		for(int i = 0; i<vertices; i++){
			if(graph[currentVertex][i] == 1 && !visited[i]){
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
	}
	printf("\n");
}

int main(){
	int graph[MAX_VERTICES][MAX_VERTICES] = {0};
	int vertices, edges, startVertex;
	
	printf("Enter number of Vertices :");
	scanf("%d", &vertices);
	
	printf("Enter number of Edges :");
	scanf("%d", &edges);
	
	printf("Enter Edges (start and end vertices of each edge) :\n");
	for(int i = 0; i<edges; i++){
		int start, end;
		scanf("%d%d", &start, &end);
		addEdge(graph, start, end);
	}
	printf("Enter the Start Vertex for BFS :\n");
	scanf("%d", &startVertex);
	
	BFS(graph, vertices, startVertex);
	return 0;
}
