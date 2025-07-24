//greedy approach for knapsack

#include<stdio.h>
//#include<conio.h>

void main(){
	int p[10],w[10],k[10],n,m,i,j,temp1,temp2,temp3;
	float x[10], profit;
	
	printf("Enter weight of Knapsack: ");
	scanf("%d", &m);
	
	printf("Enter Number of Items: ");
	scanf("%d", &n);
	
	printf("Enter Profit and weight of each item\n");
	printf("profit weight\n");
	
	for(i = 0; i<n; i++){
		scanf("%d%d", &p[i], &w[i]);
	}
	
	for(i = 0; i<n; i++){
		k[i] = p[i]/w[i];
	}
	
	for(i = 0; i < n-1; i++){
		for(j = 0; j<n-1; j++){
			if(k[j] < k[j+1]){
				temp1 = k[j];
				k[j] = k[j+1];
				k[j+1] = temp1;
				
				temp2 = p[j];
				p[j] = p[j+1];
				p[j+1] = temp2;
				
				temp3 = w[j];
				w[j] = w[j+1];
				w[j+1] = temp3;
			}
		}
	}
	
	for(i = 0; i<n; i++){
		x[i] = 0.0;
	}
	
	int u = m;
	
	for(i = 0;i <n; i++){
		if(w[i] > u){
			break;
		}
		else{
			x[i] = 1.0;
			profit += p[i];
			u -= w[i];
		}
	}
	
	if(i < n){
		x[i] = (float)u/w[i];
		profit += x[i] * p[i];
	}
	
	printf("Selection of items is : \n");
	for(i = 0; i<n; i++){
		printf("Selection = %f\n", x[i]);
	}
	printf("Maximum profit is : %f\n", profit);
}