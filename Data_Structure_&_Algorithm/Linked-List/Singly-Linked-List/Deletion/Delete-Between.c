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

sai* DeleteBetween(sai * head,int index)
{
    sai * p=head;
    sai * q=p->next;
   for (int i = 0; i < index-1; i++)
   {
        p=p->next;
        q=q->next;
   }
   
    p->next=q->next;
    free(q);
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
      head=DeleteBetween(head,1);
      display(head);
      return 0;
}