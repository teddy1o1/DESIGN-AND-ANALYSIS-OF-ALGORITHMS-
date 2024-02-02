#include <stdio.h>
#include <stdlib.h>
struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("\n\tElements are: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int BinarySearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h) {
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

int main(){
    int key,n,t;
    struct Array arr1;
    printf("Enter the total number of testcase: ");
    scanf("%d",&t);

    while(t--){
    printf("\nEnter the Size of the array: ");
    scanf("%d", &arr1.size);

    arr1.length = 0;

    arr1.A = (int *)malloc(arr1.size * sizeof(int));

    printf("\nEnter the total number of elements: ");     //Length of the array.
    scanf("%d",&n);

    printf("\nEnter the elements of the array:\n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr1.A[i]);
    }
    
    arr1.length = n;
   
    Display(arr1);

    printf("\n\nEnter the key to be searched: ");
    scanf("%d", &key);
    
    int q = BinarySearch(arr1, key);
    if(q == -1)
        printf("Not present");

    else
        printf("Found at index: %d\n", BinarySearch(arr1, key));

    free(arr1.A);
    }
    return 0;
}
