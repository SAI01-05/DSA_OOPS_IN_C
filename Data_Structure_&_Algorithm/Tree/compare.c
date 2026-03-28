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


int compare(NODE *root1,NODE * root2)
{
    if (root1==NULL && root2==NULL)
    {
        return 1;
    }
    else
    {
        if (root1!=NULL && root2!=NULL)
        {
            if (root1->data==root2->data)
            {
                if (compare(root1->left,root2->left))
                {
                    return compare(root1->right,root2->right);
                }
                
            }
            
        }
        
    }
    return 0;
    
}

int main()
{
    NODE *root1,*root2;
    root1 = create(root1);
    root2 = create(root2);
    int result=compare(root1,root2);
    if (result==1)
    {
        printf("The two tree are same\n");
    }
    else
    {
        printf("Not same\n");
    }
    
   
    return 0;
}
