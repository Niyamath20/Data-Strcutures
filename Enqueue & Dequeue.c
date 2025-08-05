#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void enqueue(int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node * temp = head;
        
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        
        temp -> next = newNode;
    }
}

void dequeue()
{
    struct Node * temp = head;
    head = head -> next;
    temp -> next = NULL;
    free(temp);
}

void display()
{
    struct Node * temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main()
{
    while(1)
    {
    printf("Enter your choice :\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        int data;
        printf("Enter data : \n");
        scanf("%d",&data);
        enqueue(data);
        break;
        
        case 2:
        dequeue();
        break;
        
        case 3:
        display();
        break;
        
        case 4:
        exit(0);
    }
    }
}
