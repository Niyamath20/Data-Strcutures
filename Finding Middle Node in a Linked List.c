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

void middle()
{
    if(head -> next == NULL)
    {
        printf("\nThe Middle element is %d\n",head -> data);
    }
    else if(head -> next -> next == NULL)
    {
        printf("\nThe Middle element is %d\n",head -> data);
    }
    else
    {
    struct Node * t1 = head;
    struct Node * t2 = head;
    
    while(t2 != NULL && t2 -> next != NULL && t2 -> next -> next != NULL)
    {
        t1 = t1 -> next;
        t2 = t2 -> next -> next;
    }
    printf("\nThe Middle element is %d",t1 -> data);
    }
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
    insert(11);
    insert(6);
    insert(88);
    insert(12);
    display();
    middle();
}











