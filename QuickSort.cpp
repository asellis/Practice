/*
Sorts an array by selecting a pivot and moving everything less than or equal
to the pivot to the left of the pivot and everything greater than to the right.
*/


#include <iostream>


void swap(int* a, int* b)
{
	// Swaps a and b
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// Pivot is the last element in the array
	int i = low-1;

	for(int j = low; j<=high-1; ++j)
	{
		// move everything less than or equal to the pivot to the left side of the array
		if(arr[j]<=pivot)
		{
			++i;	// Moves position from the left by 1 for swapping
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[high]);	// Swap the pivot into position
	// Everything left <= Pivot
	// Everything right >= Pivot
	return (i+1);	// Return pivot position

}


void QuickSort(int arr[], int low, int high)
{
	// low and high are positions in the array spanning the length
	//		or sublength in recursive calls
	if(low<high)
	{
		int pivot_index = partition(arr, low, high);	// The position where swapping takes place
		QuickSort(arr, low, pivot_index-1);				// Will partition everyting left of pivot
		QuickSort(arr, pivot_index+1, high);			// Will partition everything right of pivot

	}
}



void print(int arr[], int size)
{
	// Prints out an int array
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