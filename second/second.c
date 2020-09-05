#include <stdio.h>
#include <stdlib.h>
#define size 10000

// creating node struct 
typedef struct Node 
{	
	int value;
	struct Node *next;
} Node;

void insert(Node **hashTable, int *key) 
{
	//check if index is negative and if it is, multiply by -1
	int index = *key % size;
	if (index < 0)
	{
		index *= -1;
	}
	Node *ptr = hashTable[index];
	//check if the inserted value is already in the table
	while (ptr != NULL) 
	{
		if ((*ptr).value == *key) 
		{
			printf("duplicate\n");
			return;
		}
		ptr = (*ptr).next;
	}
	//create new node
        Node *item = (Node*) malloc(sizeof(Node));
        (*item).value = *key;
        (*item).next = hashTable[index];
        hashTable[index] = item;
	printf("inserted\n");
	return;
}


void search(Node **hashTable, int *key) 
{
	//check if index is negative and if it is, multiply by -1
	int index = *key % size;
	if (index < 0) 
	{
		index *= -1;
	}
	Node *ptr = hashTable[index];
	//find value in table
	while (ptr != NULL)
	{
		if ((*ptr).value == *key)
		{
			printf("present\n");
			return;
		}
		ptr = (*ptr).next;		
	}
	//if this loop finishes, the value is not in the table
	printf("absent\n");
	return;
}


int main(int argc, char *argv[])
{
	//make sure correct number of inputs
	if (argc < 2) {
		return -1;
	}
	//open working file
	char *filename = argv[1];
	FILE *fptr = fopen(filename,"r");
	char run[2];
	int value;
	//create hashTable
	int i;
	//use calloc instead of malloc to conserve memory
	Node *hashTable = (Node*) calloc(size, sizeof(Node*));
	//if else statements will run the program
	while (fscanf(fptr, "%s\t%d", run, &value) != EOF) {
		if (run[0] == 's'){
			search(hashTable, &value);	
		}
		// if the char is i, then insert
		else if(run[0] == 'i'){
			insert(hashTable, &value);
		}
		else
		{
			printf("error, invalid input\n");
		}	
	}
	//free allocated memory
	free(hashTable);		
	fclose(fptr);
	return 0;
}
