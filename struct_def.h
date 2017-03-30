/*THIS FILE CONTAINS ALL THE FUNCTION AND STRUCTURE DEFINITIONS REQUIRED*/

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

