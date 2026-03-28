#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* Next;
};

void  linkedListTraversal();

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocates memory for nodes in heap
    head=(struct Node*)malloc(sizeof(struct Node));
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->Next=first;

    first->data=20;
    first->Next=second;

    second->data=30;
    second->Next=third;

    third->data=555;
    third->Next=fourth;

    fourth->data=69;
    fourth->Next=NULL;

    linkedListTraversal(head);
      
      return 0;
}
void  linkedListTraversal(struct Node * ptr)
{
    while (ptr!=NULL)
    {    
        printf("%d ",ptr->data);
        ptr=ptr->Next;
    }
    return;
}