#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} NODE;


NODE *create();

NODE *search(NODE * root,int num)
{
    NODE * ptr=root;
    while (ptr!=NULL)
    {
        if (num==ptr->data)
        {
            return ptr;
        }
        if (num < ptr->data)
        {
            ptr=ptr->left;
        }
        else
        {
            ptr=ptr->right;
        }        
    }
    return NULL;
    
}


int main()
{
    NODE *root;
    root = create(root);
    printf("enter the value you want to search\n");
    int num;
    scanf("%d",&num);
    NODE * result= search(root,num);
    if (result==NULL)
    {
        printf("%d is not found in the list\n",num);
    }
    else
    {
        printf("%d is found in the %d\n",num,result);
    }
    
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
