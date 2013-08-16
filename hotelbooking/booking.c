#include <stdio.h>
#include <stdlib.h>	

void print();
void cat_entry();
int roomassign(int temp);

struct category
{
	int nr, rent;
	char ac, wifi, rs;
	char cname[15];
	struct category *next;
};

struct room
{
	int rn;
	struct category *cat;
	struct room *next;
};

typedef struct category category;
typedef struct room room;

category *head1, *tail1;
room *head2, *tail2;
int main()
{
	head1 = (category*)malloc(sizeof(category));
	head2 = (room*)malloc(sizeof(room));
	tail1 = head1;
	tail2 = head2;
	cat_entry();
	print();
	return 0;
}


void cat_entry()
{
	char choice;
	while(1)
	{
		static int n = 1;
		
		printf("Enter Category Name\n");
		scanf("%s", tail1->cname);

		printf("Enter Number of rooms\n");
		scanf("%d", &tail1->nr);

		printf("Enter rent\n");
		scanf("%d", &tail1->rent);

		printf("Enter the available facilities.\n(If available press 'y' otherwise 'n')\n");
	
		printf("AC\n");
		scanf("\n%c", &tail1->ac);	

		printf("WI-FI\n");
		scanf("\n%c", &tail1->wifi);

		printf("Room Service\n");
		scanf("\n%c", &tail1->rs);
			
		n = roomassign(n);

		printf("Do you want to add another category?\nPress 'y' for Yes, 'n' for No.\n");
		scanf("\n%c", &choice);

		if(choice == 'y')
		{
			tail1->next = (category*)malloc(sizeof(category));
			tail1 = tail1->next;
			tail2->next = (room*)malloc(sizeof(room));
			tail2 = tail2->next;
		}

		else
		{
			tail1->next = NULL;
			printf("Enteries Successful!\n");
			break;
		}

	}
}

int roomassign(int temp)
{
	int i;
	for(i = temp; i < (tail1->nr + temp); i++)
	{
		tail2->rn = i;
		tail2->cat = tail1;
		if((i + 1) < (tail1->nr + temp))
		{
			tail2->next = (room*)malloc(sizeof(room));
			tail2 = tail2->next;
		}
	
		else
		{
			tail2->next = NULL;
		}
	}
	return(i);
}

void print()
{
	char c = ' ';
	category *temp1;
	temp1 = head1;
	room *temp2;
	temp2 = head2;
	while(temp1 != NULL)
	{
		printf("CATEGORY: %s\nNUMBER OF ROOMS: %d\nRENT: %d\n", temp1->cname, temp1->nr, temp1->rent);
		printf("FACILITIES AVAILABLE\n");
		printf("AC: %c, WIFI: %c, ROOM SERVICE: %c\n", temp1->ac, temp1->wifi, temp1->rs);
		printf("ROOMS AVAILABLE: ");
		while((temp2->next != NULL) && !(strcmp(temp1->cname, temp2->cat->cname)))
		{
			printf("%d ", temp2->rn);
			temp2 = temp2->next;
			if(temp2->next == NULL)
			{
				printf("%d\n", temp2->rn);
				break;
			}
		}
		printf("\n\n");
		temp1 = temp1->next;
	}
}
