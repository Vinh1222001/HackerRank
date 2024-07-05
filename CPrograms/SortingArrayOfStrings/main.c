#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAPPED_STRINGS 1
#define NON_SWAPPED_STRINGS 0

int lexicographic_sort(const char* a, const char* b){
    if(strcmp(a, b) > 0) return SWAPPED_STRINGS;

    return NON_SWAPPED_STRINGS;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if(strcmp(a, b) < 0) return SWAPPED_STRINGS;

    return NON_SWAPPED_STRINGS;
}

int str_count_char(const char* str){ //counting number of occurences of character a in string str

    char distinct_str[2500]="";

    for (int i = 0; i < strlen(str); i++)
    {
        if(strchr(distinct_str, str[i]) == NULL){
            strncat(distinct_str, &str[i], 1);
        }
    }
    // printf("With str = %s, distinct_str= %s and len = %d\n", str, distinct_str, strlen(distinct_str));
    return strlen(distinct_str);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
    //Step 1: Counting number of distinct characters present in string a
    int num_distinct_chars_a = str_count_char(a);
    
    //Step 2: Counting number of distinct characters present in string b
    int num_distinct_chars_b = str_count_char(b);

    //Step 3: Comparing them
    //  - if a's distinct characters greater than b's => return SWAPPED_STRINGS
    //  - if a's distinct characters equal b's => return lexicographic_sort()
    //  - remain cases will return NON_SWAPPED_STRINGS

    if (num_distinct_chars_a > num_distinct_chars_b)
    {
        return SWAPPED_STRINGS;
    }

    if (num_distinct_chars_a == num_distinct_chars_b)
    {
        return lexicographic_sort(a,b);
    }

    return NON_SWAPPED_STRINGS;
    
    
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    if (len_a - len_b > 0) return SWAPPED_STRINGS;

    if(len_a == len_b) return lexicographic_sort(a,b);

    return NON_SWAPPED_STRINGS;
    
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if(cmp_func(arr[i], arr[j])){

                // printf("i = %d, j = %d, arr[i] = %s, arr[j] =%s\n", i, j, arr[i], arr[j]);
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
} 

int main(int argc, char const *argv[])
{
    int n; 
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n*sizeof(char*));

    for(int i = 0; i <n; i++){
        *(arr + i) = malloc(1024*sizeof(char));
        scanf("%s", *(arr+i));
        *(arr + i)= realloc(*(arr + i), strlen(*(arr+i))+1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);

    }

    printf("\n");

    string_sort(arr,n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
    printf("\n");
    
    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    return 0;
}

