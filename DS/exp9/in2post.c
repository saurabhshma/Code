#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
	char a;
	struct stack *next;
};

typedef struct stack node;

node *top;
char A[50];
int i;

void display();
void push(char);
char pop();
char top_stack();
int check();
void infix();

int main()
{
	int temp1, j;
	char temp;
	i = 0;
	printf("Enter the expression\n");
	scanf("%s", A);
	temp1 = strlen(A);
	for(j = temp1; j >= 0; j--)
	{
		A[j + 1] = A[j];
	}
	A[0] = '(';
	A[temp1+1] = ')';
	printf("Converted Expression is:\n");
	//printf("%s", A);
	infix();
	printf("\n");
	return 0;
}


void push(char n)
{
	node *temp1;
	temp1 = (node*)malloc(sizeof(node));
	temp1->a = n;
	temp1->next = top;
	top = temp1;
//	display();
}

char pop()
{
	char temp1;
	node *temp;
	temp1 = top->a;
	temp = top;
	top = top->next;
	free(temp);
	return(temp1);
	//display();
}

void display()
{
	node *temp;
	temp = top;
	printf("Stack is:\n");
	while(temp != NULL)
	{
		printf("%c\n", temp->a);
		temp = temp->next;
	}
}

char top_stack()
{
	return(top->a);
}

int check()
{
	if(A[i] == '^')
	{
		return(1);
	}
	
	else if(A[i] == '/' || A[i] == '*')
	{
		if(((top_stack()) == '+') || ((top_stack()) == '-'))
		{
			return(1);
		}
		
		else
		{
			return(0);
		}
	}

	else
	{
		return(0);
	}
	
}

void infix()
{
	int flag;
	char temp, temp_top;

	if(A[i] == '(')
	{	
		push(A[i]);
		i++;
		while(A[i] != ')')
		{
			infix();
		}
		temp = pop();
		while(temp != '(')
		{	
			printf("%c", temp);
			temp = pop();
		}
		i++;
	
	}
		
	else
	{
		if(isalpha(A[i]))
		{
			printf("%c", A[i]);
			i++;
		}
		
		else
		{
			flag = check();
			temp_top = top_stack();
			if((temp_top == '(') || (flag == 1))
			{
				push(A[i]);
				i++;
			}
			
			else
			{
				temp = pop();
				push(A[i]);
				printf("%c", temp);
				i++;
			}
		}
	}
}
