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

// int insertAtFirst(struct Node *head,int data)  
//ass kel tr return madhe aaplyala pointer pahijet pn te honar nai warning deil tyamul khali jas ahe ts pointer return krl

struct Node * insertAtFirst(struct Node *head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

int main()
{
      struct Node*head;
      struct Node*first;
      struct Node*second;

      head=(struct Node*)malloc(sizeof(struct Node));
      first=(struct Node*)malloc(sizeof(struct Node));
      second=(struct Node*)malloc(sizeof(struct Node));

      head->data=10;
      head->next=first;

      first->data=20;
      first->next=second;

      second->data=30;
      second->next=NULL;

      display(head);
      head=insertAtFirst(head,5);
      display(head);


      return 0;
}