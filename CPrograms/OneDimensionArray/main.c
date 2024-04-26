#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int* arr;
    int size, sum=0;

    // printf("Enter Array's size: ");
    scanf("%d", &size);

    // printf("Array's size: %d\n", size);

    arr =  (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    
    free(arr);
    printf("%d", sum );



    return 0;
}