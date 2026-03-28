#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} NODE;


NODE *create();

void postOrder(NODE * root)
{
    NODE * ptr= root;
    if (ptr!=NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ",ptr->data);
    }
    
}

int main()
{
    NODE *root;
    root = create(root);
    printf("Success\n");
    postOrder(root);
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
