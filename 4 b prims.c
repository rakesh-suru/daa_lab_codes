//prims algorithm to find minimum cost spanning tree

#include<stdio.h>
#define INF 9999
#define MAX 20

int n;
int cost[MAX][MAX];

void prims(){
	int visited[MAX] = {0};
	int no_of_edges = 0;
	int i ,j;
	int min, u, v;
	int total_cost = 0;
	visited[0] = 1;
	
	printf("Edges in Minimum Spanning Tree: \n");
	
	while(no_of_edges < n-1){
		min = INF;
		u = v = -1;
		
		for (i = 0; i<n; i++){
			if(visited[i]){
				for(j = 0; j<n; j++){
					if(!visited[j] && cost[i][j] < min){
						min  = cost[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		
		if (u != -1 && v != -1){
			printf("%d -- %d = %d\n", u, v, min);
			total_cost += min;
			visited[v] = 1;
			no_of_edges++;
		}
	}
	
	printf("Total cost of MST = %d\n", total_cost);
}

int main(){
	int i, j;
	printf("Enter number of vertices : ");
	scanf("%d", &n);
	
	printf("Enter the cost of adjacency matrix (enter 9999 if no edge) : \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &cost[i][j]);
		}
	}
	
	prims();
	return 0;
}