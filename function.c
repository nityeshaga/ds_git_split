//#define DEBUG

#ifndef DEBUG
#include "header.h"	/*the required headers and macros*/
#include "fun_dec.h"	/*the required function declarations*/
#include "struct_def.h"	/*the required structure definitions*/
#endif

#ifdef DEBUG
#include<stdio.h>
#include<stdlib.h>
#define SLL 0
#define DLL 1
#define CLL 2
typedef struct node_sll
{
	int data;
	struct node_sll *next;
} node_sll;
typedef struct list_sll
{
	struct node_sll *start;
	int noOfNodes;
} list_sll;
#endif

/*insert(): asks user for data and adds a new node to the linked list of 'type' type at a specified position 'pos'*/
int insert(void *l, int pos, int type)	//working
{
	switch(type) {

		case SLL:
			{
				struct list_sll *list= (list_sll *)l;
				struct node_sll *current= malloc(sizeof(node_sll));
				int n;
				scanf("%d", &(current->data));
				current->next= list->start;
				struct node_sll *prev_node= NULL;
				while(pos--) {
					prev_node= current->next;
					current->next= current->next->next;
				}
				if(prev_node==NULL)
					list->start= current;
				else
					prev_node->next= current;
				++(list->noOfNodes);
			}


			//free(current);


			break;

		default:
			return 1;
	}
	return 0;
}

/*printlist(): prints the list of 'type' type pointed to by 'l'*/
int printlist(void *l, int type)	//working
{
	switch(type) {

		case SLL:
			{
				struct list_sll *list= (list_sll *)l;
				struct node_sll *p= list->start;
				int count= 0;
				printf("no of nodes: %d\n", list->noOfNodes);
				while(p!=NULL && count < list->noOfNodes) {
					printf("%d. %d\n", count, p->data);
					p=p->next;
					++count;
				}
			}
			break;
		default:
			printf("Error in type");
	}
	return 0;
}

/*deleteNode(): deletes the node at position 'pos' from the list of 'type' type pointed to by 'l'*/
int deleteNode(void *l, int pos, int type)	//improvisations possible //check why commented code does not work
{
	switch(type) {

		case SLL:
			{
				list_sll *list= (list_sll *)l;
				/*node_sll *prevNode= malloc(sizeof(node_sll));	/*node prior to the one that needs to be deleted*/
				/*void *initial= prevNode;
				prevNode->data= 0;
				prevNode->next= list->start;

				while(pos--)
					prevNode= prevNode->next;

				node_sll *temp= prevNode->next;
				prevNode->next= prevNode->next->next;
				free(temp);
				if(prevNode==initial)
					list->start= prevNode->next;
				free(prevNode);*/

					node_sll *current= list->start;
					node_sll *prevNode= NULL;
					while(pos--) {
						prevNode= current;
						current= current->next;
					}
					if(prevNode==NULL)
						list->start= current->next;
					else
						prevNode->next= current->next;
					free(current);
				--(list->noOfNodes);
			}
			break;
		default:
			return 1;
	}
	return 0;
}

/*printRev(): prints the list of 'type' type pointed to by 'l'  in reverse order*/
int printRev(void *l, int type)		//bug- unable to use printlist() or delete after printRev() call
{
	switch(type) {
		case SLL:
			{
				list_sll *list= (list_sll *)l;
				int i= list->noOfNodes-1;
				node_sll *subject= malloc(sizeof(node_sll));
				node_sll *temp= subject;	/*store in order to free later*/
				subject->next= list->start;
				node_sll *front= NULL;	/*node directly in front of subject*/
				do {
					while(subject->next!=front)
						subject= subject->next;
					printf("%d. %d\n", i, subject->data);
							printf("%d\n", list->start->data);
							printf("%d\n", list->start->next->data);
							printf("%d\n", list->start->next->next->data);
							printf("%d\n", list->start->next->next->next->data);
					front= subject;
					subject->next= list->start;
					--i;
				}
				while(front!=list->start);
				//free(temp);
			}
			break;
		default:
			return 1;
	}
	return 0;
}

/*reverse(): reverses the of 'type' type pointed to by 'l'*/
int reverse(void *l, int type)	//working
{
	switch(type) {
		case SLL:
			{
				list_sll *list= (list_sll *)l;
				node_sll *prev= NULL;
				node_sll *current= list->start;
				node_sll *nnode= current->next;
				while(current!=NULL) {
					current->next= prev;	/*reverse the link*/
					prev= current;
					current= nnode;
					if(nnode!=NULL)
						nnode= nnode->next;
				}
				list->start= prev;
			}
			break;
		default:
			return 1;
	}
	return 0;
}

#ifdef DEBUG
int main(void)
{
	struct list_sll list;
	create(&list, SLL);
	insert(&list, 0, SLL);
	insert(&list, 1, SLL);
	deleteNode(&list, 1, SLL);
	printlist(&list, SLL);
	//printRev(&list, SLL);
	reverse(&list, SLL);
	printlist(&list, SLL);
	return 0;
}
#endif
