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

int LinearSearch(struct Array *arr, int key) {
    int i,count = 0;
    for(i = 0 ; i < arr -> length ; i++) {
        count++;
        if (key == arr -> A[i] ){
            //swap( &arr -> A[i] , &arr -> A[0] );
            printf("\nFound at index: %d\n",i);
            return count;
        }
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

    printf("\n\nEnter the key for search: ");
    scanf("%d", &key);
    
    int q = LinearSearch(&arr1, key);
    if(q == -1){
        printf("\nSorry Key is Not present!!\n");
        printf("\nTotal Comparisons done: %d\n",n);
        printf(".....................\n");
    }
    else{
        printf("\n\nTotal Comparisons done: %d\n",q);
       // printf("Found at index: %d\n", LinearSearch(&arr1, key));
        printf(".....................\n");
    }
    free(arr1.A);
  }
    return 0;
}