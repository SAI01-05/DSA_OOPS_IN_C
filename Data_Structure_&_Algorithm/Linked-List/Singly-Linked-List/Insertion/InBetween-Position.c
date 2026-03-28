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

struct Node* insertInBetween(struct Node*head,int data,int index)
{
    struct Node*ptr=(struct Node*)malloc (sizeof(struct Node));
    struct Node*q=head;
    int i=1;
    ptr->data=data;
    while (i!=index-1)
    {
        q=q->next;
        i+=1;
    }
    ptr->next=q->next;
    q->next=ptr;
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
      head=insertInBetween(head,25,2);
      display(head);
      return 0;
}