#include <stdio.h>
void print(int sai[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sai[i]);
    }
    printf("\n");
}
int partition(int sai[], int low, int high)
{
    int pivot = sai[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (sai[i] <= pivot)
        {
            i++;
        }
        while (sai[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = sai[i];
            sai[i] = sai[j];
            sai[j] = temp;
        }
    } while (i < j);

    temp = sai[low];
    sai[low] = sai[j];
    sai[j] = temp;
    return j;
}

// 0      6
void quicksort(int sai[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(sai, low, high);
        quicksort(sai, low, partitionIndex - 1);
        quicksort(sai, partitionIndex + 1, high);
    }
}

int main()
{
    int sai[] = {24, 30, 27, 32, 11, 21, 19};
    int size = sizeof(sai) / sizeof(int);

    print(sai, size);
    quicksort(sai, 0, size - 1);
    print(sai, size);
    return 0;
}