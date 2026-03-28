#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void heapify(int a[], int n, int i)
{
    // Initializing parent and left and right child node with formula
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // checking the condition
    // finding largest among root,left child and right child
    if ((left < n) && (a[left] > a[largest])) // for left child
    {
        largest = left;
    }
    if ((right < n) && (a[right] > a[largest])) // for right child
    {
        largest = right;
    }
    if (largest != i) // if left and right condition true nai zali tr mg he nai swap honar ani jr left
    {                 // ani right madhe kaipn true zali tr mg largest value change hoil ani mg largest !=i true hoil
        swap(&a[i], &a[largest]);
        heapify(a, n, largest); // ani mg swap hoil root madhe ani left or right child madhe
    }
}

void heapSort(int a[], int n)
{
    // To build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // heap sort  //here there is swapping of the top and last node
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[10], size;
    printf("how many element you want to stored\n"); 
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element for position %d\n", i + 1);
        scanf("%d", &a[i]);
    }
    display(a, size);

    heapSort(a, size);
    display(a, size);
    return 0;
}