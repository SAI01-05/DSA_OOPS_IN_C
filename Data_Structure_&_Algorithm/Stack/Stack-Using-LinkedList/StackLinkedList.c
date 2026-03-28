#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node;

//Global declaration of top
node * top;

//Initialization
void init(node *top)
{
    top=NULL;
}


void push(int num)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=top;
    top=newnode; 
}

int isEmpty(node *top)
{
    return (top==NULL);
}

int pop(node *top)
{
    int num;
    node *temp=top;
    num=top->data;
    top=top->next;
    free(temp);
    return num;
}

int peek(node *top)
{
    return (top->data);
}

int main()
{
      
      init(top);
      int choice,num;
     
     do
     {
        printf("Enter the choice you want to do\n1:push\n2:pop\n3:Peek\n4:EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1://push
            printf("Enter the element to be pushed\n");
            scanf("%d",&num);
            push(num);
            break;

        case 2://pop
            if (isEmpty(top))
            {
               printf("Stack is empty\n");
            }
            else
            {
                printf("The poped element is :%d\n",pop(top));
            }
            break;

        case 3://peek
            if (isEmpty(top))
            {
               printf("Stack is empty\n");
            }
            else
            {
                printf("The topmost element is :%d\n",peek(top));
            }
            break;
            

        }
     } while (choice!=4);
     
     
      
      return 0;
}