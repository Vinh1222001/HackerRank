#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main(){

    int row = 0, column =0;

    int** arr;

    int* re_arr;

    printf("Enter number of row: \n");
    scanf("%d", &row);
    printf("Enter number of column: \n");
    scanf("%d", &column);

    *arr = (int*)malloc(row*sizeof(int));

    if(arr == NULL) printf("Allocate arr failed\n");

    re_arr = (int*)malloc(row*sizeof(int));

    if(re_arr == NULL) printf("Allocate re_arr failed\n");

    printf("Initializing matrix....\n");
    for (int i = 0; i < row; i++)
    {
        *(arr+i)= (int*)malloc(column*sizeof(int));
    }

    printf("Initializing matrix finished!\n");

    for (int i = 0; i < row; i++)
    {

        *(re_arr+i) = i;

        for (int j = 0; j < column; j++)
        {
            *(*(arr+i)+j) = i+j;
        }
        
    }
    
    re_arr = realloc(re_arr, (row+2)*sizeof(int));

    *(re_arr+row) = 10;
    *(re_arr+row+1) = 12;

    printf("Print arr:\n");
    for (int i = 0; i < row+2; i++)
    {
        /* code */
        printf("%d ", *(re_arr+i));
    }

    
    printf("\nPrinting matrix:\n");

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < column; j++)
        {            
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }

    return 0;
}


// int main()
// {
//     int total_number_of_shelves;
//     scanf("%d", &total_number_of_shelves);
    
//     int total_number_of_queries;
//     scanf("%d", &total_number_of_queries);
    
//     while (total_number_of_queries--) {
//         int type_of_query;
//         scanf("%d", &type_of_query);
        
//         if (type_of_query == 1) {
//             /*
//              * Process the query of first type here.
//              */
//             int x, y;
//             scanf("%d %d", &x, &y);

//         } else if (type_of_query == 2) {
//             int x, y;
//             scanf("%d %d", &x, &y);
//             printf("%d\n", *(*(total_number_of_pages + x) + y));
//         } else {
//             int x;
//             scanf("%d", &x);
//             printf("%d\n", *(total_number_of_books + x));
//         }
//     }

//     if (total_number_of_books) {
//         free(total_number_of_books);
//     }
    
//     for (int i = 0; i < total_number_of_shelves; i++) {
//         if (*(total_number_of_pages + i)) {
//             free(*(total_number_of_pages + i));
//         }
//     }
    
//     if (total_number_of_pages) {
//         free(total_number_of_pages);
//     }
    
//     return 0;
// }
