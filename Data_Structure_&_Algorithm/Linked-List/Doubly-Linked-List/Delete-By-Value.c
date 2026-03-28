#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    struct NODE *prev;
    int data;
    struct NODE *next;

}NODE;

void create(NODE * head)
{
    NODE *newnode,*last;
    int n;
    last=head;
   printf("Enter how many nodes you want to create\n");
   scanf("%d",&n);
   for (int i = 1; i <= n; i++)
   {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->next=newnode->prev=NULL;
        printf("Enter the data of list %d\n",i);
        scanf("%d",&newnode->data);
        last->next=newnode;
        newnode->prev=last;
        last=newnode;
   }  
}

void display(NODE * head)
{
    NODE* temp;
    temp=head->next;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}

void deleteByValue(NODE *head, int num)
{
    NODE * ptr1;
    NODE * ptr2;
    ptr1=head;
    while (ptr1->next!=NULL)
    {
        if (ptr1->next->data==num)
        {
            ptr2=ptr1->next;
            ptr1->next=ptr2->next;
            if (ptr2->next!=NULL)
            {
                 ptr2->next->prev=ptr1;
            }
            free(ptr2);
            break;
        }
        ptr1=ptr1->next;
    }
    
    if (ptr1->next==NULL)
    {
       printf("Element %d not found\n",num);
    }
    
}

int main()
{
    int num;
     NODE * head=(NODE*)malloc(sizeof(NODE));
     create(head);
     display(head);

     printf("Enter the number you want to delete\n");
     scanf("%d",&num);
     deleteByValue(head,num);
     display(head);
      
      return 0;
}