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

int height(NODE *root)
{
    if (root==NULL)
    {
        return 0;
    }
    else
    {
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        if (leftheight > rightheight)
        {
            return leftheight+1;
        }
        else
        {
            return rightheight+1;
        } 
    }
}

//Count nodes at given level
int countNodesAtLevel(NODE * root,int level)
{
    if (root==NULL)
    {
        return 0;
    }
    if (level==1)
    {
        return 1;
    }
    else if (level >1)
    {
        return countNodesAtLevel(root->left,level-1)+countNodesAtLevel(root->right,level-1);
    }
    return 0;
}

//print the count
void print(NODE * root)
{
    int h=height(root);
    for (int i = 1; i <= h; i++)
    {
        int count=countNodesAtLevel(root,i);
        printf("Level %d: %d nodes\n",i,count);
    }
    
}

int main()
{
    NODE *root;
    root = create(root);

    print( root);

    return 0;
}
