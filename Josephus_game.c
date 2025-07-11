#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node* prev;
	struct Node* next;
};


struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}


struct Node* insertEnd(struct Node* head, int data)
{
	struct Node* newNode = createNode(data);

	if (head == NULL) {
		newNode->next = newNode;
		newNode->prev = newNode;
		return newNode;
	}

	struct Node* tail = head->prev;

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = head;
	head->prev = newNode;

	return head;  
}


int solveGame(struct Node* head, int k) {
	struct Node* current = head;
	while (current->next != current) {
		
		for (int count = 1; count < k; count++) {
			current = current->next;
		}

		printf("Player %d is eliminated\n", current->data);

		
		current->prev->next = current->next;
		current->next->prev = current->prev;

		
		struct Node* temp = current;
		current = current->next;

		
		if (temp == head) {
			head = current;
		}

		free(temp);
	}

	printf("Player %d is the winner!\n", current->data);
	int winner = current->data;
	free(current);
	return winner;
}


int main() {
	int n, k;
	struct Node* head = NULL;

	printf("Enter number of players: ");
	scanf("%d", &n);

	printf("Enter value of kth player to eliminate: ");
	scanf("%d", &k);

	for (int i = 1; i <= n; i++) {
		head = insertEnd(head, i);
	}

	
	solveGame(head, k);

	return 0;
}
