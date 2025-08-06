#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void push(int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode -> next = head;
        head = newNode;
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
    push(2);
    push(32);
    push(27);
    push(87);
    push(98);
    display();
    return 0;
}
