#include <iostream>

int main()
{
	// Initializing pointers a and b
	int *a;
	int *b;

	// temp pointer for later
	int *temp1;
	int *temp2;

	// Initializing and declaring variables i, j and k
	int i = 1;
	int j = 2;
	int k = 3;

	// a points to i and b points to j (reference)
	a = &i; // a points to a reference of i
	b = &j;	// b points to a reference of j
	// *a = 1, *b = 2

	// *a = i = 1, a = memory address (i)
	// *b = j = 2, b = memory address (j)

	// Changing the address of a pointer
	// temp1 points to what a points to, a points to k
	temp1 = a;	// temp1 now points to i which is 1
	a = &k;		// a now points to k which is 3 (reference)
	// *a = 3, *temp1 = 1

	// Changing the value of what a pointer points to
	// Point temp 2 to b, change b to 4
	temp2 = b;	// temp2 now points to b which is j=2
	*b = 4;		// b and j are now 4, temp2 is 4
	// *b = 4, j = 4, *temp2 = 4

	
	


	std::cout << "*a: " << *a << " a: " << a << std::endl;
	std::cout << "*b: " << *b << " b: " << b << std::endl;
	std::cout << "*temp1: " << *temp1 << " temp1: " << temp1 << std::endl;
	std::cout << "*temp2: " << *temp2 << " temp2: " << temp2 << std::endl;

	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "k: " << k << std::endl;


	return 0;
}