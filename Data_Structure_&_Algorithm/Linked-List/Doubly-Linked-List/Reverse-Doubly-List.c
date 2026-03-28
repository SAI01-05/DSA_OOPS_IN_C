#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    struct NODE * prev;
    int data;
    struct NODE * next;

}NODE;

void create(NODE * head)
{
    NODE * last,*newnode;
    int n;
    printf("Enter how many nodes you want\n");
    scanf("%d",&n);
    last=head;
    for (int i = 1; i <= n; i++)
    {
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->next=newnode->prev=NULL;
        printf("Enter the data of list %d\n",i);
        scanf("%d",&newnode->data);
        last->next=newnode;
        newnode->prev=last;
        last=newnode;
    }
    
}

void display( NODE * head)
{
    NODE * temp;
    temp=head->next;
    while (temp!=NULL)
    {
       printf("%d ",temp->data);
       temp=temp->next;
    }
    printf("\n");
    
}

void reverse(NODE *head)
{
    NODE * temp1,*temp2;
    temp1=head->next;
    temp2=temp1->next;
    temp1->next=NULL;
    temp1->prev=temp2;
    while (temp2!=NULL)
    {
        temp2->prev=temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp2->prev;
    }
    head->next=temp1;

    

}



int main()
{
      int num;
      int pos;
      NODE *head=(NODE *)malloc(sizeof(NODE));
      create(head);
      display(head);

      reverse(head);
      display(head);

      return 0;
}