#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}NODE;



void create(NODE * head)
{
    int n;
    NODE *last,*newnode;
    printf("Enter how many nodes you want\n");
    scanf("%d",&n);
    last=head;
    for (int i = 1; i <= n; i++)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->next=NULL;
        printf("Enter the data of %d node\n",i);
        scanf("%d",&newnode->data);
        last->next=newnode;
        last=newnode;
    }
}


void display(NODE * head)
{
    NODE * ptr;
    ptr=head->next;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

void reverse1(NODE * head)
{
    NODE *t1=head->next,*t2,*t3;
    if (t1==NULL)
    {
        return;
    }
    t2=t1->next;
    if (t2==NULL)
    {
       return;
    }
    t3=t2->next;
    t1->next=NULL;
    while (t3!=NULL)
    {
        t2->next=t1;
        t1=t2;
        t2=t3;
        t3=t3->next;
    }
    t2->next=t1;
    head->next=t2;
    
     
}





int main()
{
    NODE *head=(NODE*)malloc(sizeof(NODE));
    create(head);
    display(head);

    reverse1(head);
    printf("After reversing linked list\n");
    display(head);    
    return 0;
}