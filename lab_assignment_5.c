#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* tmp = head;
	int amount = 0;
	if (tmp == NULL)
		return amount;
	while (tmp != NULL) {
		amount++;
		tmp=tmp->next;
	}
	return amount;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head);
	char* str =(char*) malloc(sizeof(char) * (len + 1));
	node *tmp = head;
	char* invalid = "invalid";
	if (tmp == NULL)
		return invalid;
	for (int i=0; i<len; i++){
		str[i]= tmp->letter;
		tmp=tmp->next;
	}
	str[len]='\0';
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*) malloc(sizeof(node));
	node* curr = *pHead;
	if (newNode == NULL)
		exit(-1);
	newNode->letter=c;
	newNode->next = NULL;
	if (*pHead == NULL) 
		*pHead = newNode;
	else {
		while (curr->next != NULL)
			curr=curr->next;
		curr->next=newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmp = *pHead;
	while (tmp != NULL){
		*pHead = tmp->next;
		free(tmp);
		tmp = *pHead;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}