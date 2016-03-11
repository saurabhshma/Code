#include <iostream>
#include "getRandomNumber.h"

using namespace std;

void hilo()
{
	int myNumber = getRandomNumber(1, 100), userNumber;
	cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
	for(int i = 1; i <= 7; i++)
	{
		cout << "Guess #" << i << ": ";
		cin >> userNumber;
		if(myNumber == userNumber)
		{
			cout << "Correct! You Win!\n";
			return;
		}
		else if(myNumber < userNumber)
			cout << "High!\n";
		else
			cout << "Low!\n";
	}
	
	cout << "Sorry! You lose! Correct number was " << myNumber << "\n";
}

int main()
{
	char choice;
	do
	{
		hilo();
		while(1)
		{
			cout << "Would you like to play again? (y/n)\n";
			cin >> choice;
			if(choice == 'y' || choice == 'n')
				break;
		}
	} while(choice == 'y');
	return 0;
}
