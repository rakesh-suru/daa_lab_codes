//Travelling Salesperson problem using brute force approach

#include<stdio.h>
#include<limits.h>
#define v 4

int tsp(int graph[v][v], int path[], int visited[], int pos, int count, int cost, int start){
	if(count == v && graph[pos][start]){
		return cost + graph[pos][start];
	}
	int ans = INT_MAX;
	int i = 0;
	for(i = 0; i<v; i++){
		if(!visited[i] && graph[pos][i]){
			visited[i] = 1;
			path[count] = i;
			int tempCost = tsp(graph, path, visited, i, count + 1, cost + graph[pos][i], start);
			if(tempCost < ans){
				ans = tempCost;
				visited[i] = 0;
			}
		}
	}
	return ans;
}

int main(){
	int graph[v][v] = {{0,10,15,20}, {10,0,35,25}, {15,35,0,30}, {20,25,30,0}};
	int visited[v] = {0}, path[v];
	visited[0] = 1;
	path[0] = 0;
	int minCost = tsp(graph, path, visited, 0, 1, 0, 0);
	printf("Minimum Cost of visiting all cities is %d\n", minCost);
	return 0;
}