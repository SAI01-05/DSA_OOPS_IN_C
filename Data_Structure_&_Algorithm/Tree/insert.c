#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} NODE;


NODE *create();

NODE * reInsert(NODE * root,int num)
{
    NODE * newnode,*p=root;
    newnode=(NODE *)malloc (sizeof(NODE));
    newnode->data=num;
    newnode->left=newnode->right=NULL;
    if (root==NULL)
    {
        root=newnode;
        return root;
    }
    if (num==p->data)
    {
        printf("Duplicate value not allowed\n");
        return root;
    }
    
    if (num < p->data)
    {
        p->left=reInsert(p->left,num);
    }
    else
    {
        p->right=reInsert(p->right,num);
    }
    return root;
    
    
}
void inOrder(NODE * root)
{
    NODE * ptr=root;
    if (ptr!=NULL)
    {
       inOrder(ptr->left);
       printf("%d ",ptr->data);
       inOrder(ptr->right);
    }
    
}


int main()
{
    NODE *root;
    root = create(root);
    printf("BST created successfully\n");
    printf("Enter the element you want to insert\n");
    int num;
    scanf("%d",&num);
    root=reInsert(root,num);
    inOrder(root);
    return 0;
}
NODE *create(NODE *root)
{
    NODE *newnode, *p;
    int n, num;
    printf("Enter how many nodes you want\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        //creation of newnode
        newnode = (NODE *)malloc(sizeof(NODE));
        printf("Enter the data:");
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = newnode->right = NULL;

        //asssign 1st node as root
        if (i == 1)
        {
            root = newnode;
        }
        // assign remaining nodes as per order
        else
        {
            p = root;
            while (p != NULL)
            {
                if (newnode->data > p->data)
                {
                    if (p->right == NULL)
                    {
                        p->right = newnode;
                        break;
                    }
                    else
                    {
                        p = p->right;
                    }
                }
                else
                {
                    if (p->left == NULL)
                    {
                        p->left = newnode;
                        break;
                    }
                    else
                    {
                        p = p->left;
                    }
                }
            }
        }
    }
    return root;
}
