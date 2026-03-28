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

void merge(NODE * head1,NODE *head2,NODE *head3)
{
    NODE *t1=head1->next;
    NODE *t2=head2->next;
    NODE * newnode;
    NODE * last=head3;

    while (t1!=NULL && t2!=NULL)
    {
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->next=NULL;
        if (t1->data < t2->data)
        {
            newnode->data=t1->data;
            t1=t1->next;
        }
        else
        {
            newnode->data=t2->data;
            t2=t2->next;
        }
        last->next=newnode;
        last=newnode;
    }

    while (t1!=NULL)
    {
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->next=NULL;
        newnode->data=t1->data;
        t1=t1->next;
        last->next=newnode;
        last=newnode;
    }

    while (t2!=NULL)
    {
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->next=NULL;
        newnode->data=t2->data;
        t2=t2->next;
        last->next=newnode;
        last=newnode;
    }
    
    
}

int main()
{
    NODE * head1=(NODE *)malloc (sizeof(NODE));
    NODE * head2=(NODE *)malloc (sizeof(NODE));
    NODE * head3=(NODE *)malloc (sizeof(NODE));

    printf("Creation of 1st node\n");
    create(head1);
    display(head1);

    printf("Creation of 2nd node\n");
    create(head2);
    display(head2);

    merge(head1,head2,head3);
    display(head3);
      
      return 0;
}