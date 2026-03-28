#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int vertex;
    struct node * next;
}NODE;
NODE * list[10];

void createList(int m[10][10],int vertices)
{
    NODE *temp,*newnode;
    for (int i = 1; i <= vertices; i++)
    {
        list[i]=NULL;
        for (int j = 1; j <= vertices; j++)
        {
          if (m[i][j]==1)
          {
            newnode=(NODE*)malloc(sizeof(NODE));
            newnode->vertex=j;
            newnode->next=NULL;
            if (list[i]==NULL)
            {
                list[i]=temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
            
          }
          
        }
        
    }
    
}

void displayList(int vertices)
{
    NODE *temp;
    printf("The adjacency list is \n");
    for (int i = 1; i <= vertices; i++)
    {
        printf("%d->",i);
        temp=list[i];
        while (temp)
        {
            printf("%d->",temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
        
    }
    
}



int main()
{
    //  int m[10][10]={{0,1,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,1,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,1}}, vertices;
     int m[10][10], vertices;
    printf("Enter how many vertices you want\n");
    scanf("%d", &vertices);
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("is there is edge between %d -> %d\n", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // Display adjacency matrix
    printf("The adjacency matrix is as below\n");
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }


    createList( m, vertices);
    displayList(vertices);
}