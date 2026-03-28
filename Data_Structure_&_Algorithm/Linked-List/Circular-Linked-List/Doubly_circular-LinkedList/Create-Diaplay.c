#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    struct NODE * prev;
    int data;
    struct NODE * next;

}NODE;


void create(NODE *head)
{
    NODE *  newnode,*last;
    int n;
    printf("How many nodes\n");
    scanf("%d",&n);
    last=head;
    for (int i = 1; i <=n; i++)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        printf("Enter the value of node\n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        newnode->prev=last;
        last->next=newnode;
        last=newnode;
        head->prev=newnode;
    }
    
}

void display(NODE * head)
{
    NODE * ptr=head->next;
    while (ptr!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


int main()
{
      NODE * head=(NODE*)malloc (sizeof(NODE));
      create(head);
      display(head);
      
      return 0;
}