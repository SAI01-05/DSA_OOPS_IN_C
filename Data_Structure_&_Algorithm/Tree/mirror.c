#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} NODE;


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

NODE * mirror(NODE * root)
{
    NODE * ptr=root,*temp;
    if (ptr!=NULL)
    {
        if (ptr->left!=NULL)
        {
            mirror(ptr->left);
        }
        if (ptr->right!=NULL)
        {
            mirror(ptr->right);
        }
        temp=ptr->left;
        ptr->left=ptr->right;
        ptr->right=temp; 
    }
}



int main()
{
    NODE *root,*root2;
    root = create(root);
    inOrder(root);
    root2= mirror(root);
    inOrder(root2);
    
    return 0;
}
