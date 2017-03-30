/*THIS FILE CONTAINS THE SOURCE CODE FOR OPERATIONS ON A SINGLY CONNECTED LINKED LIST*/

#include "header.h"	/*the required headers and macros*/
#include "struct_def.h"	/*the required structure definitions*/
#include "fun_dec.h"	/*the required function declarations*/
int main(void)
{
	/*user-driven menu*/
	list_sll list1;
	list1.start= NULL;
	list1.noOfNodes= 0;
	printf( "Creating the first node of a new list\n"
                "Enter the data\n");
	insert(&list1, 0, SLL);
	int choice;
	do {
		printf( "\nEnter:\n1. INSERT@end: to insert a new node at the end of the list\n"
			"2. INSERT@beg: to insert a new node at the start of the list\n"
			"3. INSERT: to select the position and insert the node there\n"
			"4. DELETE: to delete a node at the chosen position\n"
			"5. PRINT: print the list\n"
			"6. PRINT@rev: print the list in reverse order\n"
			"7. REVERSE: reverse the list\n"
			"0. QUIT: quit this menu\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("INSERT@end:\n");
				if(insert(&list1, list1.noOfNodes, SLL)) {
					printf("An error has occured\n");
					return EXIT_FAILURE;
				}
				break;
			case 2:
				printf("INSERT@beg:\n");
				if(insert(&list1, 0, SLL)) {
					printf("An error has occured\n");
					return EXIT_FAILURE;
				}
				break;
			case 3:
				printf("INSERT:\n");
				{
					printf("Enter the position at which you want to insert the new node\n");
					int pos;
					scanf("%d", &pos);
					if(pos>=0 && pos<=list1.noOfNodes) {
		                                printf("Creating a node at position %d\n", pos);
		                                printf("Enter the data\n");
						if(insert(&list1, pos, SLL)) {
							printf("An error has occured\n");
							return EXIT_FAILURE;
						}
					}
					else
						printf("Can't insert at that position\n");
				}
				break;
			case 4:
				printf("DELETE:\n");
				{
					printf("Enter the position of the node that you want to delete\n");
					int pos;
					scanf("%d", &pos);
					if(pos>=0 && pos<list1.noOfNodes) {
						if(deleteNode(&list1, pos, SLL)) {
							printf("An error has occured\n");
							return EXIT_FAILURE;
						}
						else
			                                printf("Node at position %d deleted\n", pos);
					}
					else
						printf("Can't delete at that position\n");
				}
				break;
			case 5:
				printf("PRINT:\n");
                                printf("Printing the list:\n");
				if(printlist(&list1, SLL)) {
					printf("An error has occured\n");
					return EXIT_FAILURE;
				}
				break;
			case 6:
				printf("PRINT@rev:\n");
				printf("Printing the list in reverse\n");
				if(printRev(&list1, SLL)) {
					printf("An error has occured\n");
					return EXIT_FAILURE;
				}
				break;
			case 7:
				printf("REVERSE:\n");
				if(reverse(&list1, SLL)) {
					printf("An error has occured\n");
					return EXIT_FAILURE;
				}
				else
					printf("List reversed\n");
				break;
			case 0:
				break;
			default:
				printf("Incorrect choice entered\n");
		}
	}
	while(choice);
	return EXIT_SUCCESS;
}
