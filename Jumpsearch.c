#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\n\tElements are: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int jumpsearch(struct Array arr, int key)
{
    int i, j, count = 0, l = 0, r = pow(2, 0);

    while (l < arr.length)
    {
        count++;
        if (arr.A[l] == key)
            return l;

        if (arr.A[l] < key)
        {
            l = r;
            r = pow(2, i) + l;
            i++;
        }
        else
        {
            l = l + pow(2, i - 1) + 1;
        }

        if (l > arr.length - 1)
            return -1;

        if (arr.A[l] < key)
        {
            j = BinarySearch(arr, key);
            return j;
        }
    }

    return -1;
}

int main()
{
    int key, n, t;
    struct Array arr1;
    printf("Enter the total number of testcase: ");
    scanf("%d", &t);

    while (t--)
    {
        printf("\nEnter the Size of the array: ");
        scanf("%d", &arr1.size);

        arr1.length = 0;

        arr1.A = (int *)malloc(arr1.size * sizeof(int));

        printf("\nEnter the total number of elements: "); // Length of the array.
        scanf("%d", &n);

        printf("Enter the elements of the array: \n");
        for (int i = 0; i < n; i++)
        {
            printf("Input #A[%d]: ", i);
            scanf("%d", &arr1.A[i]);
        }

        arr1.length = n;

        Display(arr1);

        printf("\n\nEnter the key to be searched: ");
        scanf("%d", &key);

        int q = jumpsearch(arr1, key);
        if (q == -1)
            printf("Not present");

        else
            printf("Found at index: %d\n", jumpsearch(arr1, key));
    }
    free(arr1.A);
    return 0;
}