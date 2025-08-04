#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void insert(int data)
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

void reverse()
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    
    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
    printf("\nReversed List\n");
}

void display()
{
    struct Node * temp = head;
    
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    insert(5);
    insert(10);
    insert(12);
    insert(14);
    printf("Original data\n");
    display();
    reverse();
    display();
}
