#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * prev;
    struct Node * next;
};

struct Node * head = NULL;
struct Node * tail = NULL;

void insert(int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    
    if(head == NULL)
    {
        head = tail = newNode; 
    }
    else
    {
        struct Node * temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        tail = newNode;
        newNode -> prev = temp;
    }
}

void delete(int val)
{
    struct Node * temp = head;
    while(temp != NULL)
    {
        if(temp -> prev == NULL && temp -> data == val)
        {
            head = temp -> next;
            temp -> next -> prev = NULL;
            temp -> next == NULL;
            free(temp);
            return;
        }
        else if(temp -> next == NULL && temp -> data == val)
        {
            tail = tail -> prev;
            temp -> prev -> next = NULL;
            temp -> prev = NULL;
            free(temp);
            return;
        }
        else if (temp -> prev != NULL && temp -> next != NULL && temp -> data == val)
        {
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            temp -> prev = NULL;
            temp -> next = NULL;
            free(temp);
            return;
        }
        temp = temp -> next;
    }
    printf("Not found\n");
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
    printf("Enter no of elements to enter : ");
    int n;
    scanf("%d",&n);
    int i;
    while(n--)
    {
        scanf("%d",&i);
        insert(i);
    }
    display();
    printf("\nEnter the value to delete : ");
    int val;
    scanf("%d",&val);
    //printf("\n");
    delete(val);
    display();
    return 0;
}
