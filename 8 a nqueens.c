#include<stdio.h>
#include<stdbool.h>
#define N 8

int board[N][N] = {0};

bool isSafe(int row, int col){
	int i,j;
	for(i = 0; i < col; i++){
		if(board[row][i]){
			return false;
		}
	}
	
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if(board[i][j]){
			return false;
		}
	}
	
	for(i = row, j = col; i < N && j >= 0; i++, j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}

bool solveNQ(int col){
	if(col >= N){
		return true;
	}
	int i;
	for(i = 0; i < N; i++){
		if(isSafe(i, col)){
			board[i][col] = 1;
			if(solveNQ(col+1)){
				return true;
			}
			board[i][col] = 0;
		}
	}
	return false;
}

void printSolution(){
	int i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d\t", board[i][j]);
		}
	printf("\n");
	}
}

int main(){
	if( !solveNQ(0)){
		printf("Solution does not exist\n");
	}
	else{
		printSolution();
	}
	return 0;
}