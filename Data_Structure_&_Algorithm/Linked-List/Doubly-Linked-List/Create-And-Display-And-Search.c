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

void search (NODE * head,int num)
{
    NODE * temp;
    temp=head->next;
    int pos=0;
    while (temp!=NULL)
    {
        pos+=1;
        if (temp->data==num)
        {
            printf("The data found at position %d\n",pos);
            break;
        }
        temp=temp->next;

         if (temp==NULL)
         {
             printf("Element not found\n");
        }
    }
    
    
}


int main()
{
      int num;
      NODE *head=(NODE *)malloc(sizeof(NODE));
      create(head);
      display(head);
      printf("Enter the data you want to search in the list\n");
      scanf("%d",&num);
      search(head,num);
      return 0;
}