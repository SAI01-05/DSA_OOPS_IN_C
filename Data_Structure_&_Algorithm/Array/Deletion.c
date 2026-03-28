#include <stdio.h>
void show(int sai[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", sai[i]);
    }
    printf("\n");
}

void deletion(int sai[], int size, int index)
{                // 3       //5
    for (int i = index-1; i < size; i++)
    {
        sai[i] = sai[i+1];
    }
}

int main()
{
    int size = 5, index = 4 ;
    int sai[10] = {5, 15, 25, 35, 45};
    show(sai, size);

    deletion(sai, size, index);
    size -= 1;
    show(sai, size);

    return 0;
}