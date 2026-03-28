#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int coeff,exp;
    struct NODE * next;

}POLY;

void create(POLY * head)
{
    int n;
    POLY *ptr,*newnode;
    printf("enter how many terms you want\n");
    scanf("%d",&n);
    ptr=head;
    for (int i = 1; i <=n; i++)
    {
        newnode=(POLY *)malloc (sizeof(POLY));
        newnode->next=NULL;
        printf("Enter the coeff and exponential\n");
        scanf("%d%d",&newnode->coeff,&newnode->exp);
        ptr->next=newnode;
        ptr=newnode;
    }
    
}
void display(POLY * head)
{
    POLY *ptr;
    ptr=head->next;
    while (ptr!=NULL)
    {
        printf("<%dx^%d>+",ptr->coeff,ptr->exp);
        ptr=ptr->next;
    }
    printf("\n");
    
}
void add(POLY *p1,POLY *p2,POLY *p3)
{

    POLY *ptr1,*ptr2,*ptr3,*newnode;
    ptr1=p1->next;
    ptr2=p2->next;
    ptr3=p3;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        newnode=(POLY *)malloc(sizeof(POLY));
        newnode->next=NULL;
        if (ptr1->exp > ptr2->exp)
        {
            newnode->coeff=ptr1->coeff;
            newnode->exp=ptr1->exp;
            ptr1=ptr1->next;
        }
        else if (ptr2->exp >ptr1->exp)
        {
            newnode->coeff=ptr2->coeff;
            newnode->exp=ptr2->exp;
            ptr2=ptr2->next;
        }
        else
        {
            newnode->exp=ptr1->exp;
            newnode->coeff=ptr1->coeff +ptr2->coeff;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr3->next=newnode;
        ptr3=newnode;
    }
    while (ptr1)
    {
       newnode=(POLY *)malloc(sizeof(POLY));
       newnode->next=NULL;
       newnode->coeff=ptr1->coeff;
       newnode->exp=ptr1->exp;
       ptr3->next=newnode;
       ptr3=newnode;
       ptr1=ptr1->next;
    }
    while (ptr2)
    {
       newnode=(POLY *)malloc(sizeof(POLY));
       newnode->next=NULL;
       newnode->coeff=ptr2->coeff;
       newnode->exp=ptr2->exp;
       ptr3->next=newnode;
       ptr3=newnode;
       ptr2=ptr2->next;
    }
    
    
}

int main()
{
      POLY *p1,*p2,*p3;
      p1=(POLY *)malloc(sizeof(POLY));
      p2=(POLY *)malloc(sizeof(POLY));
      p3=(POLY *)malloc(sizeof(POLY));

      create(p1);
      display(p1);
      create(p2);
      display(p2);
      add(p1,p2,p3);
      display(p3);
      return 0;
}