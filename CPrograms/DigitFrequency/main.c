#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int arr[10]={0,0,0,0,0,0,0,0,0,0};

    char* str;
    str = malloc(1024 * sizeof(char));
    scanf("%[^\n]", str);
    str = realloc(str, strlen(str) + 1);


    for (int i = 0; i < strlen(str); i++)
    {
        if(*(str+i) >=48 && *(str+i)<=57){
            arr[*(str+i)-48]++;            
        }
    }
    
    printf("%d", arr[0]);
    for (int i = 1; i < 10; i++)
    {
        /* code */
        printf(" %d",arr[i]);
    }
    
    
    return 0;
}
