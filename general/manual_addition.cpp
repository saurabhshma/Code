#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char A[10], B[10], C[11], temp;
	int carry = 0;
	cout << "Enter 1st number\n";
	cin >> A;
	cout << "Enter 2nd number\n";
	cin >> B;
	int a_len, b_len, largest_len;
	a_len = strlen(A);
	b_len = strlen(B);

	if(a_len >= b_len)
		largest_len = a_len;
	else
		largest_len = b_len;

	C[largest_len] = '\0';

	for(int i = largest_len - 1; i >= 0; i--)
	{
		if(a_len > 0 && b_len > 0)
		{
			temp = A[a_len - 1] + (B[b_len - 1] - 48) + carry;
			if(temp > 57)
			{
				C[i] = temp - 10;
				carry = 1;
			}
			else
			{
				C[i] = temp;
				carry = 0;
			}
			a_len--;
			b_len--;
		}
		else if(a_len <= 0 && b_len > 0)
		{
			temp = B[b_len - 1] + carry;
			if(temp > 57)
			{
				C[i] = temp - 10;
				carry = 1;
			}
			else
			{
				C[i] = temp;
				carry = 0;
			}
			b_len--;
		}
		else
		{
			temp = A[a_len - 1] + carry;
			if(temp > 57)
			{
				C[i] = temp - 10;
				carry = 1;
			}
			else
			{
				C[i] = temp;
				carry = 0;
			}
			a_len--;
		}
	}
	cout << "Sum of " << A << " + " << B << " = ";
	if(carry == 1)
		cout << "1" << C << endl;
	else
		cout << C << endl;
	return 0;
}
