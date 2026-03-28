#include <stdio.h>
void print(int sai[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sai[i]);
    }
    printf("\n");
}

void Insertion(int *sai, int size)
{
    int check,j;
    //loop for passes
    for (int i = 1; i <= size - 1; i++)
    {
        check=sai[i];
        j=i-1;
        //for each pass
        while (j>=0 && sai[j]>check)
        {
            sai[j+1]=sai[j];
            j--;
        }
        sai[j+1]=check;
        print(sai,size);
    
    }
}
        
int main()
{            
    int sai[] = {22, 14, 25, 10, 5};
    int size = sizeof(sai) / sizeof(int);
    print(sai, size);
    Insertion(sai, size);
    // print(sai, size);
    return 0;
}