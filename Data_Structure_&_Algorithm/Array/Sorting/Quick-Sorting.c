#include <stdio.h>

void print(int sai[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sai[i]);
    }
    printf("\n");
    return;
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

    // swap sai[low] and sai[j]
    temp = sai[low];
    sai[low] = sai[j];
    sai[j] = temp;
    return j;
}

void QuickSort(int sai[], int low, int high)
{
    int partionIndex; // index of pivot after partition

    if (low < high)
    {
        partionIndex = partition(sai, low, high);
        QuickSort(sai, low, partionIndex - 1);  // sort left subarray
        QuickSort(sai, partionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int sai[] = {24, 30, 27, 32, 11, 21, 19};
    int size = sizeof(sai) / sizeof(int);

    print(sai, size);

    QuickSort(sai, 0, size - 1);
    print(sai, size);
    return 0;
}
