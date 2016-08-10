//https://www.hackerrank.com/challenges/time-conversion
#include <iostream>
#include <string>

using namespace std;

int extract_hour(string &input);

int main()
{
	string input;
	cin >> input;
	char output[9];
	if(input[8] == 'A')
	{
		if(input[0] == '1' && input[1] == '2')
		{
			input[0] = '0';
			input[1] = '0';
			/*for(int i = 0; i < 8; i++)
				output[i] = input[i];*/
			input.resize(8);
		}
		else
			/*for(int i = 0; i < 8; i++)
				output[i] = input[i];*/
			input.resize(8);
	}
	else
	{
		int hour = extract_hour(input);
		hour = hour % 12 + 12;
		input[0] = hour / 10 + 48;
		input[1] = hour % 10 + 48;
		/*for(int i = 0; i < 8; i++)
				output[i] = input[i];*/
		input.resize(8);
	}
	//output[8] = '\0';
	cout << input;
	return 0;
}

int extract_hour(string &input)
{
	int value = (input[0] - 48) * 10 + (input[1] - 48);
	return (value);
}
