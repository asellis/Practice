/*
Recursively sorts the left and right halves of an array.
As the recursion returns from the base case, the left and right
halves of the array will be sorted.  The algorithm then compares
the first items in the left and right halves that have been sorted
and puts the minimal value into a new array which will be returned.
The algorithm then moves to the next element in either the left or
right half, depending on which element was put into the array.
*/

#include <iostream>

void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid-left +1;
	int n2 = right - mid;

	int L[n1], R[n2];	// Arrays to hold left and right side of mid
	// L and R will already be sorted

	// Copy left and right side of array into L and R
	for (i=0; i<n1; i++)
		L[i]=arr[left+i];
	for (j=0; j<n2; j++)
		R[j]=arr[mid+1+j];

	i=0;
	j=0;
	k=left;

	while(i<n1 && j<n2)
	{
		// Move smaller element of either L or R into array
		// L and R are already sorted
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int left, int right)
{
	if(left<right)
	{
		int mid = left+(right-left)/2;	// middle index, same as (left+right)/2

		MergeSort(arr, left, mid);		// MergeSort left half
		MergeSort(arr, mid+1, right);	// MergeSort right half

		merge(arr, left, mid, right);
	}

}

void print(int arr[], int size)
{
	// Prints out array
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
	MergeSort(arr, 0, n-1);
	print(arr, 5);

	int arr2[] = {10, 5, 0, 1, -6, 201, 13, 666, 23, 16, 21, 80};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	print(arr2, n2);
	MergeSort(arr2, 0, n2-1);
	print(arr2, n2);
	

	return 0;
}