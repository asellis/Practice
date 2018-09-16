all:
	g++ MergeSort.cpp -o MergeSort --std=c++11
	g++ QuickSort.cpp -o QuickSort --std=c++11

merge:
	g++ MergeSort.cpp -o MergeSort --std=c++11

quick:
	g++ QuickSort.cpp -o QuickSort --std=c++11

clean:
	rm MergeSort
	rm QuickSort