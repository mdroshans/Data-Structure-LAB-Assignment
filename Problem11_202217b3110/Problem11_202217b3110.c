#include <stdio.h>

int linearSearch(int array[], int size, int target) 
{
    int i;   
    for (i = 0; i < size; i++)  
    {
        if (array[i] == target) 
        {
            return i;   
        }
    }
    return -1;  
}

int main()  
{   
    int array[] = {10, 2, 8, 5, 17};   
    int size = sizeof(array) / sizeof(array[0]);   
    int target = 8;   
    int result = linearSearch(array, size, target);   
    if (result == -1) 
    {
        printf("Element not found in the array.\n");  
    }
    else
    {
        printf("Element found at index: %d\n", result);  
    }
    return 0;  
}
