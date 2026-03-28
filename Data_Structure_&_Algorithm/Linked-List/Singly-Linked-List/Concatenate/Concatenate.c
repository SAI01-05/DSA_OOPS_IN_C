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

void concatenate (NODE *head1,NODE * head2)
{
    NODE* ptr=head1->next;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head2->next;
    
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
    NODE * head1=(NODE *)malloc (sizeof(NODE));
    NODE * head2=(NODE *)malloc (sizeof(NODE));

    printf("Creation of 1st node\n");
    create(head1);
    display(head1);

    printf("Creation of 2nd node\n");
    create(head2);
    display(head2);

    concatenate(head1,head2);
    display(head1);
      
      return 0;
}