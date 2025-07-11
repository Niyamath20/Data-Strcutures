//Audio Playlist using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	char song[100];
	struct Node *next;
};


struct Node* head=NULL;

struct Node* createNode(char song[]) 
{ 
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->song, song);
	newNode->next=NULL;
	return newNode;
}

void addSong(char song[]) {
	struct Node* newNode=createNode(song);
	newNode->next=head;
	head=newNode;
	printf("\n%s added to the playlist\n\n",song);
}

void display() {
	if(head==NULL)
	{
		printf("\nNo songs to play...\n\n");
		return;
	}
	struct Node* temp=head;
	while(temp!=NULL) {
		printf("%s ->",temp->song);
		temp=temp->next;
	}
	printf(" NULL\n\n");
}
int main() {
    
	int choice;
	char songName[100];
	while(1) {
		printf("Choice 1: Add a song\nChoice 2: Display songs\nChoice 3: Exit\n\nEnter your choice : ");
		scanf("%d",&choice);
		getchar();
		switch(choice) {
		case 1:
			printf("Enter song name : ");
			fgets(songName, sizeof(songName), stdin);
			songName[strcspn(songName, "\n")] = 0;
			addSong(songName);
			break;
		case 2:
			display();
			break;
		case 3:
			printf("Exiting playlist");
			exit(0);
		default:
			printf("Enter valid choice");
		}
	}
	return 0;
}
