#include <stdio.h>
#include <stdlib.h>
#define size 5

int A[size];
int front, rear;

void create(int n);
void display();
void ins();
void del();

int main()
{
	int n, choice;
	printf("Enter the number of elements (max 5)\n");
	scanf("%d", &n);
	create(n);
	while(1)
	{
		printf("Choose and option.\n1. INSERT\n2. DELETE\n3. EXIT\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				ins();
				break;
			case 2:
				del();
				break;
			case 3:
				exit(1);
			default:
				printf("Wrong Choice!!!\n");
		}
	}
	
}

void create(int n)
{
	int i;
	front = 0, rear = n - 1;
	printf("Start entering elements\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	display();
}

void ins()
{
	int a;
	if(rear < size - 1)
	{
		printf("Enter the value of number\n");
		scanf("%d", &a);
		A[rear + 1] = a;
		rear++;
		display();
	}
	
	else
		printf("Overflow!\n");
}

void del()
{
	if(front > rear)
	{
		printf("Underflow!\n");
	}

	else
	{
		front++;
		display();
	}
}

void display()
{
	int i;
	printf("Queue is:\n");
	for(i = front; i <= rear; i++)
	{
		printf("%d\n", A[i]);
	}
}

OUTPUT:
Enter the number of elements (max 5)
4
Start entering elements
1
2
3
4
Queue is:
1
2
3
4
Choose and option.
1. INSERT
2. DELETE
3. EXIT
1
Enter the value of number
2
Queue is:
1
2
3
4
2
Choose and option.
1. INSERT
2. DELETE
3. EXIT
3

