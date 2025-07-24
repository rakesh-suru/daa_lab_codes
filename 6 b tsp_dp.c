//Travelling Salesperson problem using dynamic programming

#include<stdio.h>
#include<limits.h>
#define V 4
#define VISITED_ALL ((1 << V) - 1)

int dp[1<<V][V];
int tsp(int mask, int pos, int graph[V][V]){
	if(mask == VISITED_ALL){
		return graph[pos][0];
	}
	if(dp[mask][pos] != -1){
		return dp[mask][pos];
	}
	int ans = INT_MAX;
	int city;
	for(city = 0; city < V; city++){
		if((mask & (1 << city)) == 0){
			int newAns = graph[pos][city] + tsp(mask | (1 << city), city, graph);
			if(newAns < ans){
				ans = newAns;
			}
		}
	}
	return dp[mask][pos] = ans;
}

int main(){
	int graph[V][V] = {{0,10,15,20}, {10,0,35,25}, {15,35,0,30}, {20,25,30,0}};
	int i, j;
	for(i = 0; i < (1 << V); i++){
		for(j = 0; j < V; j++){
			dp[i][j] = -1;
		}
	}
	int minCost = tsp(1,0,graph);
	printf("Minimum Cost of visiting all cities is %d\n", minCost);
	return 0;
}