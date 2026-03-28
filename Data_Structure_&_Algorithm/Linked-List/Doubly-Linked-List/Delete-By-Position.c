#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *prev;
    int data;
    struct NODE *next;

} NODE;

void create(NODE *head)
{
    NODE *last, *newnode;
    int n;
    printf("Enter how many nodes you want\n");
    scanf("%d", &n);
    last = head;
    for (int i = 1; i <= n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = newnode->prev = NULL;
        printf("Enter the data of list %d\n", i);
        scanf("%d", &newnode->data);
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
}

void display(NODE *head)
{
    NODE *temp;
    temp = head->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(NODE *head, int pos)
{
    NODE *temp1, *temp2;
    int i;
    for (temp1 = head, i = 1; (temp1->next != NULL) && (i <= pos - 1); i++)
    {
        temp1 = temp1->next;
        if (temp1->next == NULL)
        {
            printf("position out of range\n");
            return;
        }
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    if (temp2->next != NULL)
    {

        temp1->next->prev = temp1;
    }

    free(temp2);
}

int main()
{
    int pos;
    NODE *head = (NODE *)malloc(sizeof(NODE));
    create(head);
    display(head);

    printf("Enter the position you want to delete \n");
    scanf("%d", &pos);
    delete (head, pos);
    display(head);

    return 0;
}