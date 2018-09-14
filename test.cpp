#include <iostream>
#include <vector>

void test()
{
	static int a = 0;
	++a;
	std::cout << a <<std::endl;
}

int main()
{
	std::cout << "Begin Program" << std::endl;

	// Dynamic Allocation
	int l = 4;
	int* a = new int[l];
	for(int i=0;i<l;++i)
	{
		a[i]=i;
	}
	for(int i=0;i<l;++i)
	{
		std::cout << "a[" << i << "]: " << a[i] << std::endl;
	}
	
	delete[] a;

	/*
	// Messing with pointers
	char str[] = "Hello";
	char* str2 = str;

	std::cout << "str:\t" << str << std::endl;
	std::cout << "&str:\t" << &str << std::endl;
	std::cout << "*str:\t" << *str << std::endl;
	std::cout << "str2:\t" << str2 << std::endl;
	std::cout << "&str2:\t" << &str2 << std::endl;
	std::cout << "*str2:\t" << *str2 << std::endl;

	
	int a[2][2] = {1,2,3,4};
	for(int i=0; i<2; ++i)
	{
		for(int j=0; j<2; ++j)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << a[1][1] << std::endl;

	
	test();
	test();
	int b;
	1==2 ? b=1:b=0;
	std::cout << b << std::endl; 

	
	int values[8]={1,2,3,4,5,6,7,8};
	try{}
	catch(...){}
	
	std::string str = "Test String";
	str.erase(str.find('s'), 0);
	std::cout << str << std::endl;

	// Use the string iterator to store the elements in a vector
	std::vector<char> strvec(str.begin(), str.end());

	strvec.push_back('e');
	strvec.erase(strvec.end()-1);

	// Print out each element of string str
	for(char c : str)
	{
		std::cout << c << "\t";
	}
	std::cout << std::endl;

	// Print out each element of vector<char> strvec
	for(char c : strvec)
	{
		std::cout << c;
		//std::cout << bool(c == 'e');
	}
	std::cout << std::endl;

	// Convert to upper case
	for(int i=0; i<str.length(); ++i)
	{
		str[i] = toupper(str[i]);
		std::cout << str[i];
	}
	std::cout << std::endl;

	*/
	std::cout << "End Program" << std::endl;
	return 0;
}

