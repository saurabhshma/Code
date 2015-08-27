#include <iostream>

int readNumber()
{
	int value;
	std::cin >> value;
	return (value); 	
}
	
void writeAnswer(int result)
{
	std::cout << result << std::endl;	
}

int main()
{
	int val_1, val_2;
	std::cout << "Enter 1st value" << std::endl;
	val_1 = readNumber();
	std::cout << "Enter 2nd value" << std::endl;
	val_2 = readNumber();
	std::cout << val_1 << " + " << val_2 << " = ";
	writeAnswer(val_1 + val_2);
	return 0;
}
