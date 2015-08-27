#include <iostream>
#include <iomanip>

enum name
{
	shamma,
	saurab,
	yo	
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int ch = 10;
	int a = 4;
	cout << sizeof(name);
	float c = static_cast<float> (10) / 4;
	cout << std::setprecision(10) << c << endl;
	return 0;
}
