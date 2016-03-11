#include <iostream>
#include "constants.h"

double getHeight()
{
	double height;
	std::cout << "Enter the initial height of the tower:\n";
	std::cin >> height;
	return height; 
}

void printHeight(double height)
{
	int time = 0;
	double currentHeight = height;
	while(true)
	{
		if(currentHeight > 0)
		{
			std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << " meters\n";
			++time;
			currentHeight = height - (myConstants::gravity * time * time) / 2;
		}
		else
		{
			currentHeight = 0;
			std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << " meters\n";
			break;
		}
	}
}

int main()
{
	double height;
	height = getHeight();
	printHeight(height);
	return 0;
}
