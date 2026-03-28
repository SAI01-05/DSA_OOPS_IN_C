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





void printGivenLevel(NODE * root,int level)
{
    if (root==NULL)
    {
        return;
    }
    if (level==1)
    {
        printf("%d ",root->data);
    }
    else if (level>1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

void printlevelOrder(NODE * root)
{
    int h=height(root);
    for (int i = 1; i <= h; i++)
    {
        printf("level %d:",i);
        printGivenLevel(root,i);
        printf("\n");
    }
    
}
    


int main()
{
    NODE *root;
    root = create(root);

    printlevelOrder(root);

    return 0;
}
