/*THIS FILE CONTAINS main() AND OTHER FUNCTIONS RELATED TO CREATING AND PERFORMING BASIC OPERATIONS ON A STACK (using linked list)*/

#include"header.h"
#include"struct_def.h"
#include"fun_dec.h"

list_sll stack1;

void push(void);
void pop(void);

int main(void)
{
	printf( "Create a stack by pushing an element\n"
			"Enter the first element to be pushed\n");
	int ele;
	//scanf("%d", &ele);
	insert(&stack1, 0,  SLL);
	int choice;
	do {
		printf( "Enter:\n1. PUSH: to push an element at the top of stack\n"
			"2. POP: to pop an element from the top of stack\n"
			"3. PRINT: to print the contents of the stack\n"
			"0. EXIT: to exit this menu\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the element to be pushed\n");
				push();
				break;
			case 2:
				printf("Popping..\n");
				pop();
				break;
			case 3:
				//printRev(&stack1, SLL);
					printlist(&stack1, SLL);
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

void push(void)
{
	insert(&stack1, stack1.noOfNodes, SLL);
}

void pop(void)
{
	if(stack1.noOfNodes<1)
		printf("UNDERFLOW!\nNothing to pop\n");
	else {
		deleteNode(&stack1, stack1.noOfNodes-1, SLL);
		printf("Popped\n");
	}
}
