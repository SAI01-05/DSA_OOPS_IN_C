#include<stdio.h>
#define maxsize 3

typedef struct Stack
{
   int data[maxsize];
   int top;
}Stack;


//For initialization
void initstack(Stack *s)
{
    s->top=-1;
}


//For push and condition
void push(Stack *s,int num)
{
    s->data[++s->top]=num;
    printf("%d is inserted\n",num);
}
int isfull(Stack *s)
{
    return (s->top==maxsize-1);
}


//For pop and condition
int pop(Stack *s)
{
    return(s->data[s->top--]);
}
int isempty(Stack *s)
{
    return(s->top==-1);
}



//For access topmost element
int peek(Stack * s)
{
    int num;
    num=s->data[s->top];
    return num;
}

int main()
{
      Stack s;
      initstack(&s);
      int choice,num;

    //Remove do and while for only each operation
      do
      {
        printf("Enter the choice you want to do\n1:push\n2:pop\n3:Peek\n4:EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1://push
            if(isfull(&s))
            {
                printf("stack overflow\n\n");
            }
            else
            {
                printf("Enter the value to be inserted\n");
                scanf("%d",&num);
                push(&s,num);
            }
            break;

        case 2://pop
            if(isempty(&s))
            {
                printf("stack underflow\n\n");
            }
            else
            {
                printf("The poped element is %d\n",pop(&s));    
            }
            break;

        case 3://peek
            if (isempty(&s))
            {
               printf("stack underflow\n\n");
            }
            else
            {
                printf("The topmost element is %d\n",peek(&s));
            }
            
        }



      } while (choice!=4);
      
      
      
      return 0;
} 