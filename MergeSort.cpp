#include <iostream>

void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid-left +1;
	int n2 = right - mid;

	int L[n1], R[n2];

	for (i=0; i<n1; i++)
		L[i]=arr[left+i];
	for (j=0; j<n2; j++)
		R[j]=arr[mid+1+j];

	i=0;
	j=0;
	k=left;

	while(i<n1 && j<n2)
	{
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
		int mid = left+(right-left)/2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		merge(arr, left, mid, right);
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
	MergeSort(arr, 0, n-1);
	print(arr, 5);

	int arr2[] = {10, 5, 0, 1, -6, 201, 13, 666, 23, 16, 21, 80};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	print(arr2, n2);
	MergeSort(arr2, 0, n2-1);
	print(arr2, n2);
	

	return 0;
}