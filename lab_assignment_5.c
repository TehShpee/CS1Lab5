#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* temp = head;
	int count = 0;
	while (temp != NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* temp = head;
	char* string = (malloc(sizeof(char) * length(head)));
	int i=0;
	while (temp != NULL)
	{
		string[i] = temp->letter;
		temp = temp -> next;
		i++;
	}
	string[i] = '\0';
	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = *pHead;
	if (temp != NULL){
	while (temp->next != NULL)
		temp=temp->next;
	}
	node* new = (malloc(sizeof(node)));
	new->letter = c;
	new->next = NULL;
	if (temp == NULL)
	*pHead = new;
	else
	temp->next = new;

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* temp = *pHead;
	while (temp != NULL)
	{
		temp=temp->next;
		free(*pHead);
		*pHead = temp;

	}
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