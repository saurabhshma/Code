#include <stdio.h>
#include <stdlib.h>

struct category
{
	int nr, rent;
	char ac, wifi, rs;
	char cname[15];
	struct category *next;
};

struct room
{
	int rn, nd;
	struct room *next;
};

typedef struct category category;
typedef struct room room;

int main()
{
	void cat_entry(category *node1);
	category *head1;
	head1 = (category*)malloc(sizeof(category));
	cat_entry(head1);
	return 0;
}

void cat_entry(category *node1)
{
	char choice;
	printf("Enter Category Name\n");
	scanf("%s", node1 -> cname);

	printf("Enter Number of rooms\n");
	scanf("%d", &node1 -> nr);

	printf("Enter rent\n");
	scanf("%d", &node1 -> rent);

	printf("AC\n");
	scanf("\n%c", &node1 -> ac);

	printf("WI-FI\n");
	scanf("\n%c", &node1 -> wifi);

	printf("Room Service\n");
	scanf("\n%c", &node1 -> rs);

	printf("Do you want to add another category?\nPress 'y' for Yes, 'n' for No.\n");
	scanf("\n%c", &choice);

	if(choice == 'y')
	{
		node1 -> next = (category*)malloc(sizeof(category));
		cat_entry(node1 -> next);
	}

	else
	{
		node1 -> next = NULL;
		printf("Enteries Successful!\n");
	}

}
