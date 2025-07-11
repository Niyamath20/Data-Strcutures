#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char clue[100];
	struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(char clue[]) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->clue, clue);
	newNode->next = NULL;
	return newNode;
}

void addClue(char clue[]) {
	struct Node* newNode = createNode(clue);
	if (head == NULL) {
		head = newNode;
		return;
	}
	struct Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

void displayClues() {
	if (head == NULL) {
		printf("No clues added yet!\n");
		return;
	}
	printf("All Clues in the Hunt:\n");
	struct Node* temp = head;
	int i = 1;
	while (temp != NULL) {
		printf("Clue %d: %s\n", i, temp->clue);
		temp = temp->next;
		i++;
	}
}

void startHunt() {
	if (head == NULL) {
		printf("No clues in the hunt yet!\n");
		return;
	}
	printf("\nStarting the Scavenger Hunt!\n");
	struct Node* temp = head;
	int step = 1;
	while (temp != NULL) {
		printf("Step %d: %s\n", step, temp->clue);
		temp = temp->next;
		step++;
	}
	printf("You found the treasure!\n");
}

int main() {
	int choice;
	char clue[100];
	while (1) {
		printf("\n--- Scavenger Hunt Menu ---\n");
		printf("1. Add a clue\n");
		printf("2. Display all clues\n");
		printf("3. Start the hunt\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf(" %d", &choice);
		getchar();
		switch (choice) {
		case 1:
			printf("Enter clue: ");
			fgets(clue, sizeof(clue), stdin);
			clue[strcspn(clue, "\n")] = '\0';
			addClue(clue);
			break;
		case 2:
			displayClues();
			break;
		case 3:
			startHunt();
			break;
		case 0:
			printf("Exiting...\n");
			return 0;
		default:
			printf("Invalid choice. Try again!\n");
		}
	}
	return 0;
}
