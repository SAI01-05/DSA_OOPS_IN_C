#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}sai;

void display(sai *head)
{
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    
}

sai* DeleteByValue(sai * head,int value)
{
    sai * p=head;
    sai * q=head->next;

    while (q->data!=value &&  q->next!=NULL )
    {
       q=q->next;
       p=p->next;
    }
    if (q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
    
}

int main()
{
      sai *head;
      sai *first;
      sai *second;
      sai *third;

      head=(sai*)malloc(sizeof (sai));
      first=(sai*)malloc(sizeof (sai));
      second=(sai*)malloc(sizeof (sai));
      third=(sai*)malloc(sizeof (sai));

      head->data=10;
      head->next=first;

      first->data=20;
      first->next=second;
      
      second->data=30;
      second->next=third;

      third->data=40;
      third->next=NULL;

      display(head);
      head=DeleteByValue(head,30);
      display(head);
      return 0;
}