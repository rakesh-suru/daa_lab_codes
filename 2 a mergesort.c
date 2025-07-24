#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int left, int mid, int right){
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	int* L = (int*)malloc(n1* sizeof(int));
	int* R = (int*)malloc(n2* sizeof(int));
	
	if(L == NULL || R == NULL){
		printf("Memory Allocation Failed\n");
		exit(1);
	}
	
	for(i = 0; i < n1; i++){
		L[i] = arr[left + i];
	}
	for(j = 0; j < n2; j++){
		R[j] = arr[mid + 1 + j];
	}
	i = 0;
	j = 0; 
	k = left;
	
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void mergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = left + (right - left)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

void printArray(int arr[], int size){
	for(int i = 0; i<size; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	
	if(arr == NULL){
		printf("Memory Allocation Failed\n");
		return 1;
	}
	
	printf("Enter %d elements :\n", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	mergeSort(arr, 0, n-1);
	end = clock();
	cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
	
	printf("Sorted Array : ");
	printArray(arr, n);
	printf("Time taken to sort : %f seconds\n", cpu_time_used);
	free(arr);
	return 0;
}
