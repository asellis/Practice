#include <iostream>
#include "add.hpp"

// compile using: g++ main.cpp add.cpp -o main -std=c++11
// have to have both main.cpp and add.cpp to find all the files, header declared in each
// -o main is the output file
// -std=c++11 required for initializing using {}

int main()
{
	int a{1}, b{2};
	std::cout << "a:\t" << a << std::endl;
	std::cout << "b:\t" << b << std::endl;
	std::cout << "a+b:\t" << add(a,b) << std::endl;

	

	return 0;
}