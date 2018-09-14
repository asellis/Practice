#include <iostream>


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1;

	for(int j = low; j<=high-1; ++j)
	{
		if(arr[j]<=pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[high]);
	return (i+1);

}


void QuickSort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pivot_index = partition(arr, low, high);
		QuickSort(arr, low, pivot_index-1);
		QuickSort(arr, pivot_index+1, high);

	}
}



void print(int arr[], int size)
{
	for(int i=0; i<size; ++i)
	{
		std::cout << arr[i];
		if(i!=size-1)
			std::cout << ' ';
	}
	std::cout << std::endl;

}

int main()
{
	int arr[] = {4, 3, 1, 5, 2};

	print(arr, 5);

	int n = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr, 0, n-1);
	print(arr, 5);

	int arr2[] = {10, 5, 0, 1, -6, 201, 13, 666, 23, 16, 21, 80};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	print(arr2, n2);
	QuickSort(arr2, 0, n2-1);
	print(arr2, n2);
	

	return 0;
}