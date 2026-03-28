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

void insert( NODE * head,int num,int pos)
{
    NODE *temp1,*temp2,*newnode;
    int i;
    for (temp1=head,i=1;(temp1!=NULL)&& (i<=pos-1);i++)
    {
        temp1=temp1->next;
        if (temp1==NULL)
        {
            printf("Position out of range");
            return;
        }
    }
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=num;
    newnode->next=newnode->prev=NULL;
    temp2=temp1->next;
    newnode->next=temp2;
    temp2->prev=newnode;
    temp1->next=newnode;
    newnode->prev=temp1; 
    
   


}


int main()
{
      int num;
      int pos;
      NODE *head=(NODE *)malloc(sizeof(NODE));
      create(head);
      display(head);

      printf("Enter the value and position you want to insert data\n");
      scanf("%d %d",&num,&pos);
      insert(head,num,pos);
      display(head);

      return 0;
}