#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	srand(static_cast<int>(time(0)));
	for(int i = 1; i <= 20; i++)
	{
		cout << getRandomNumber(1, 6) << " ";
	}
	return 0;
}
