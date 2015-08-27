#include <iostream>

int readNumber()
{
	int value;
	std::cout << "Enter Value" << std::endl;
	std::cin >> value;
	return (value); 	
}
	
void writeNumber(int result)
{
	std::cout << "Result is = " << result << std::endl;	
}
