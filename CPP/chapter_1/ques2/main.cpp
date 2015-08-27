int readNumber();
void writeNumber(int result);

int main()
{
	int val_1, val_2;
	val_1 = readNumber();
	val_2 = readNumber();
	writeNumber(val_1 + val_2);
	return 0;
}
