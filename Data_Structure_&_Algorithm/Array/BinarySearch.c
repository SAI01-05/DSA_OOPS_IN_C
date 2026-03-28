#include <stdio.h>
int Binary();

int main()
{
    int sai[] = {10, 20, 40, 55, 56, 58};
    int size = sizeof(sai) / sizeof(int);
    int element = 56;
    printf("The element %d was found at index no %d\n", element, Binary(sai, size, element));

    return 0;
}
int Binary(int sai[], int size, int element)
{
    int low, high, mid;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (sai[mid] == element)
        {
            return mid;
        }

        if (sai[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}