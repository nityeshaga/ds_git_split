/*THIS FILE CONTAINS main() AND OTHER FUNCTIONS RELATED TO CREATING AND PERFORMING BASIC OPERATIONS ON A queue (using linked list)*/

#include"header.h"
#include"struct_def.h"
#include"fun_dec.h"

list_sll queue1;

void enqueue(void);
void dequeue(void);

int main(void)
{
	printf( "Create a queue by enqueuing an element\n"
			"Enter the first element to be entered\n");
	int ele;
	insert(&queue1, 0,  SLL);
	int choice;
	do {
		printf( "Enter:\n1. ENQUEUE: to enqueue an element at the end of queue\n"
			"2. DEQUEUE: to dequeue an element from the start of queue\n"
			"3. PRINT: to print the contents of the queue\n"
			"0. EXIT: to exit this menu\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the element to be enqueueed\n");
				enqueue();
				break;
			case 2:
				printf("dequeuing..\n");
				dequeue();
				break;
			case 3:
					printlist(&queue1, SLL);
				break;
			case 0:
				break;
			default:
				printf("Invalid option\n");
		}
	}
	while(choice);
	return EXIT_SUCCESS;
}

void enqueue(void)
{
	insert(&queue1, queue1.noOfNodes, SLL);
}

void dequeue(void)
{
	if(queue1.noOfNodes<1)
		printf("UNDERFLOW!\nNothing to dequeue\n");
	else {
		deleteNode(&queue1, 0, SLL);
		printf("dequeued\n");
	}
}
