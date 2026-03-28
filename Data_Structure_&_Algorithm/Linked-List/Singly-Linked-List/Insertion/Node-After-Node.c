#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void display(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


struct Node* insertAfterNode(struct Node *head,struct Node *prevNode,int data)
{
    struct Node* ptr=(struct Node*)malloc (sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;

}

int main()
{
       struct Node*head;
      struct Node*first;
      struct Node*second;
      struct Node*third;

      head=(struct Node*)malloc(sizeof(struct Node));
      first=(struct Node*)malloc(sizeof(struct Node));
      second=(struct Node*)malloc(sizeof(struct Node));
      third=(struct Node*)malloc(sizeof(struct Node));

      head->data=10;
      head->next=first;

      first->data=20;
      first->next=second;

      second->data=30;
      second->next=third;

      third->data=40;
      third->next=NULL;


      display(head);
      head=insertAfterNode(head,second,69);
      display(head);
      return 0;
}