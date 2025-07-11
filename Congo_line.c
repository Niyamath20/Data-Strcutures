#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node 
{
	char name[30];
	struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(char name[]) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}


void joinLine(char name[]) {
	struct Node* newNode = createNode(name);

	if (head == NULL) {
		head = newNode;
		return;
	}

	struct Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}


void leaveLine() {
	if (head == NULL) {
		printf("Congo line is empty!\n");
		return;
	}

	struct Node* temp = head;
	printf("%s has left the congo line.\n", temp->name);
	head = head->next;
	free(temp);
}


void displayLine() {
	if (head == NULL) {
		printf("Congo line is empty!\n");
		return;
	}

	printf("Congo Line: ");
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%s", temp->name);
		if (temp->next != NULL)
			printf(" -> ");
		temp = temp->next;
	}
	printf("\n");
}


int main() {
	int choice;
	char name[30];

	while (1) {
		printf("\n Congo Line \n");
		printf("1. Join the congo line\n");
		printf("2. Leave the congo line\n");
		printf("3. Display the congo line\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter name: ");
			scanf("%s", name);
			joinLine(name);
			break;
		case 2:
			leaveLine();
			break;
		case 3:
			displayLine();
			break;
		case 0:
			printf("Exiting program.\n");
			return 0;
		default:
			printf("Invalid choice. Try again.\n");
		}
	}

	return 0;
}
