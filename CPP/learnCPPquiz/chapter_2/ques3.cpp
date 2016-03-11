#include <iostream>

double getOperand()
{
	using namespace std;
	double value;
	cout << "Enter the value\n";
	cin >> value;
	return value;
}

double getOperator()
{
	using namespace std;
	char op;
	cout << "Enter one of the following: (+, -, *, /)\n";
	cin >> op;
	return op;
}

void printResult(double value_1, double value_2, char operation)
{
	using namespace std;
	double result;
	switch(operation)
	{
		case '+': 
			result = value_1 + value_2;
			cout << value_1 << " " << operation << " " << value_2 << " = " << result << "\n";
			break;
		case '-':
			result = value_1 - value_2;	
			cout << value_1 << " " << operation << " " << value_2 << " = " << result << "\n";
			break;
		case '*':
			result = value_1 * value_2;
			cout << value_1 << " " << operation << " " << value_2 << " = " << result << "\n";
			break;
		case '/':
			result = value_1 / value_2;
			cout << value_1 << " " << operation << " " << value_2 << " = " << result << "\n";
			break;
		default:
			cout << "Wrong operation selected!\n";

	}


}

int main()
{
	double x, y;
	char operation;
	x = getOperand();
	y = getOperand();
	operation = getOperator();
	printResult(x, y, operation);
	return 0;
}
