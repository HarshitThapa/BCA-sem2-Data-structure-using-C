#include <stdio.h>

/* Linear Search Function */
int linearSearch(int arr[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }

    return -1;
}

/* Binary Search Function */
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[100], n, i, key;
    int result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (sorted for binary search):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    /* Linear Search */
    result = linearSearch(arr, n, key);

    if(result != -1)
        printf("Linear Search: Element found at position %d\n", result + 1);
    else
        printf("Linear Search: Element not found\n");

    /* Binary Search */
    result = binarySearch(arr, n, key);

    if(result != -1)
        printf("Binary Search: Element found at position %d\n", result + 1);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
