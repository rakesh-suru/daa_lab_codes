//Dijikstra Algorithm

#include<stdio.h>
#include<limits.h>
#define MAX 100

int minDistance(int dist[], int visited[], int V){
	int min = INT_MAX, minIndex;
	int v;
	for (v = 0; v < V; v++){
		if( !visited[v] && dist[v] <= min){
			min = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void printSolution(int dist[], int V){
	printf("Vertex\t Distance from Source\n");
	int i = 0;
	for(i = 0; i < V; i++){
		printf("%d\t\t %d\n", i, dist[i]);
	}
}

void dijkstra( int graph[MAX][MAX], int V, int src){
	int dist[MAX];
	int visited[MAX];
	int i, v, count;
	for(i = 0; i<V; i++){
		dist[i] = INT_MAX;
		visited[i] = 0;
	}
	dist[src] = 0;
	for(count = 0; count < V-1; count++){
		int u = minDistance(dist, visited, V);
		visited[u] = 1;
		for(v = 0; v < V; v++){
			if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, V);
}

int main(){
	int V, src;
	int graph[MAX][MAX];
	int i, j;
	printf("Enter number of Vertices : ");
	scanf("%d", &V);
	printf("Enter Adjacency matrix (%d x %d)  : \n", V, V);
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			scanf("%d", &graph[i][j]);
		}
	}
	printf("Enter source vertex (0 to %d) : ", V-1);
	scanf("%d", &src);
	dijkstra(graph, V, src);
	return 0;
}