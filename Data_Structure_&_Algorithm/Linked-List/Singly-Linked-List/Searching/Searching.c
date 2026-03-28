#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
}sai;

void Searching(sai *head,int value)
{
    sai * ptr=head;
    int flag,index=0;
    while (ptr!=NULL)
    {
       if (ptr->data==value)
       {
           flag=1;
           break;   
       }
       ptr=ptr->next;  
    }
    if (flag==1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Not found\n");
    }
    return;
    
}

int main()
{
      sai *head;
      sai *first;
      sai *second;
      sai *third;

      head=(sai*)malloc(sizeof (sai));
      first=(sai*)malloc(sizeof (sai));
      second=(sai*)malloc(sizeof (sai));
      third=(sai*)malloc(sizeof (sai));

      head->data=10;
      head->next=first;

      first->data=20;
      first->next=second;
      
      second->data=30;
      second->next=third;

      third->data=40;
      third->next=NULL;

      int value;
      printf("Enter element to be search\n");
      scanf("%d",&value);
      Searching(head,value);
      return 0;
}