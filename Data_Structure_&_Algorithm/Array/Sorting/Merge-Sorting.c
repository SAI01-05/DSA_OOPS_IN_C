#include <stdio.h>
void print(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void mergeSort();
void merge();
int main()
{
    int A[] = {92, 35, 4, 14, 4, 15, 46};
    int size = sizeof(A) / sizeof(int);
    print(A, size);
    mergeSort(A, 0, size-1);
    print(A, size);
    return 0;
}
void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[10];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}