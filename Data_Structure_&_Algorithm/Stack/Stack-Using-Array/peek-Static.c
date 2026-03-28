#include <stdio.h>
#define maxsize 3

typedef struct Stack
{
    int data[maxsize];
    int top;
} Stack;

// For initialization
void initstack(Stack *s)
{
    s->top = -1;
}

// For push and condition
void push(Stack *s, int num)
{
    s->data[++s->top] = num;
    printf("%d is inserted\n", num);
}
int isfull(Stack *s)
{
    return (s->top == maxsize - 1);
}



int main()
{
    Stack s;
    initstack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    for (int i = s.top; i >= 0; i--)
    {
       printf("%d ",s.data[i]);
    }
    
    
}
