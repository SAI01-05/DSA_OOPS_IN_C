#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;

void create(NODE * head)
{
    NODE* last, * newnode;
    int n;
    printf("Enter the number of nodes you want to create\n");
    scanf("%d",&n);
    last=head;
   for (int i = 1; i <= n; i++)
    {   
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->next=NULL;
        printf("Enter the data of %d node\n",i);
        scanf("%d",&newnode->data);
        last->next= newnode;
        last=newnode;
    }
}

void sort(NODE * head)
{
    NODE *i,*j;
    int temp;
    for ( i = head->next; i->next!=NULL; i=i->next)
    {
       for ( j = i->next; j!=NULL; j=j->next)
       {
            if (i->data > j->data)
            {
                temp=i->data;
                i->data =j->data;
                j->data=temp;
            }  
       }
       
    }
}


void display(NODE * head)
{
    NODE * ptr=head->next;
    while (ptr!=NULL)
    {
       printf("%d ",ptr->data);
       ptr=ptr->next;
    }
    printf("\n");
    
}



int main()
{
    NODE * head=(NODE *)malloc (sizeof(NODE));
   
    create(head);
    display(head);

    sort(head);
    display(head);

   
      return 0;
}