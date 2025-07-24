#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int left = low;
	int right = high - 1;
	
	while(1){
		while(left <= right && arr[left] < pivot){
			left++;
		}
		while(right >= left && arr[right] > pivot){
			right--;
		}
		if(left >= right){
			break;
		}
		swap(&arr[left], &arr[right]);
		left++;
		right--;
	}
	swap(&arr[left], &arr[high]);
	return left;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int pivotIndex = partition(arr, low, high);
		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
	}
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter number of Elements :");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Memory Allocation Failed\n");
		return 1;
	}
	
	printf("Enter %d elements\n", n);
	for(int i = 0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	quickSort(arr, 0, n-1);
	end = clock();
	cpu_time_used = ((double)(end -start))/CLOCKS_PER_SEC;
	printf("Sorted Array :");
	printArray(arr, n);
	printf("Time Taken to sort : %f seconds\n", cpu_time_used);
	free(arr);
	return 0;
}


