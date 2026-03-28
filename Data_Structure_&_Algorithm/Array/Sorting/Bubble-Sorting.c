#include <stdio.h>
void print(int *sai, int size) //  (int sai[], int size )
{
    for (int i = 0; i < size ; i++)
    {
        printf("%d ", sai[i]);
    }
    printf("\n");
    return;
}

void BubbleSort();

int main()
{
    int sai[] = {25,36,75,84,0};
    int size = sizeof(sai) / sizeof(int);
    print(sai, size);

    BubbleSort(sai, size);
    print(sai, size);
    return 0; 
}

void BubbleSort(int sai[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) // For passes
    {
        for (int j = 0; j < size - 1 -i; j++) // for swapping
        {
            if (sai[j] > sai[j + 1])
            {
                temp = sai[j];
                sai[j] = sai[j + 1];
                sai[j + 1] = temp;
            }
        }
    }
}