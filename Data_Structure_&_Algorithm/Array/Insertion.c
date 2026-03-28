#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void insert(int sai[], int capacity, int size, int element, int index)
{

    for (int i = size - 1; i >= index - 1; i--)
    {
        sai[i + 1] = sai[i];
    }
    sai[index - 1] = element;
}

int main()
{
    int size = 4, element = 25, index = 3;
    int sai[10] = {10, 20, 30, 40};
    display(sai, size);

    insert(sai, 10, size, element, index);
    size += 1;
    display(sai, size);
    return 0;
}