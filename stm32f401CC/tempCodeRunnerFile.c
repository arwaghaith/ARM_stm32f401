//lease provide C code that determines the maximum repeated element in an array.

// For example, given the array [1, 2, 2, 3, 3, 3, 4, 4, 4, 4], the maximum repeated element is

// 4, and the number of repetitions is 4.

// The function signature is:

#include <stdio.h>

int maxRepeated(int arr[], int n)

{

    int max = arr[0];
    int min=arr[0];
    int max_repeated = 0;
    int max_repeated_element = arr[0];

    //getting the maximum value in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    //getting the minimum value in the array

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    //creating an array to store the number of repetitions of each element

    int* count = (int*)calloc((max - min + 1) , sizeof(int));

    //counting the number of repetitions of each element

    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    //getting the maximum number of repetitions

    for (int i = 0; i < (max - min + 1); i++)
    {
        if (count[i] > max_repeated)
        {
            max_repeated = count[i];
            max_repeated_element = i + min;
        }
    }

    return max_repeated_element;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The maximum repeated element is %d\n", maxRepeated(arr, n));
    return 0;
}