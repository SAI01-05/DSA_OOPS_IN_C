#include <stdio.h>
void show(int *sai, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sai[i]);
    }
    printf("\n");
}

void selectionSort(int sai[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        int selectedIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (sai[j] < sai[selectedIndex])
            {
                selectedIndex = j;
            }
        }
        temp = sai[i];
        sai[i] = sai[selectedIndex];
        sai[selectedIndex] = temp;
    }
}

int main()
{
    int sai[] = {21, 11, 3, 15, 5, 26, 10};
    int size = sizeof(sai) / sizeof(int);
    show(sai, size);
    selectionSort(sai, size);
    show(sai, size);
    return 0;
}