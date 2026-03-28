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

NODE * delete(NODE *root,int num)
{
    NODE *ptr;
    if (root==NULL)
    {
        return root;
    }
    if (num < root->data)
    {
        root->left=delete(root->left,num);
    }
    else if (num > root->data)
    {
        root->right=delete(root->right,num);
    }
    else
    {
        if (root->left==NULL)
        {
            ptr=root->right;
            free(root);
            return ptr;
        }
        else if (root->right==NULL)
        {
            ptr=root->left;
            free(root);
            return ptr;
        }
        ptr=root->right;
        while (ptr && ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        root->data=ptr->data;
        root->right=delete(root->right,ptr->data);  
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
    //    printf("\n");
    }
    
}

int main()
{
    NODE *root;
    root = create(root);
    inOrder(root);
    printf("\n");
    NODE* root1=delete(root,11);
    inOrder(root1);
    printf("\n");
    return 0;
}
