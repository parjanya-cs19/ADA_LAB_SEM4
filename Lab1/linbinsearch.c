#include<stdio.h>
#include<stdlib.h>

int linearSearch(int array[], int size, int val) 
{ 
    for (int i = 0; i < size; i++) 
        if (array[i] == val) 
            return i; 
    return -1; 
} 

int binarySearch(int array[], int val, int low, int high)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == val)
        {
            return mid;
        }
        if (array[mid] > val)
        {
            return binarySearch(array, val, low, mid - 1);
        }
        return binarySearch(array, val, mid + 1, high);
    }
    return -1;
}
 
int main() 
{
    int n=0, choice, key;
    printf("\nEnter the size of Array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter the value for %d th position of Array : ",(i+1));
        scanf("%d",&arr[i]);
    }
    for(;;)
    {
        printf("\nMenu\n1. Linear Search\n2. Binary Search\n3.Exit\nEnter the choice from menu : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter the element to be searched : ");
                scanf("%d",&key);
                int linres = linearSearch(arr, n, key);
                if (linres == -1)
                    printf("Element not found!!");
                else
                    printf("Item is present at index %d", linres);
                break;
            case 2:
                printf("\nEnter the element to be searched : ");
                scanf("%d",&key);
                int binres = binarySearch(arr, key, 0, n);
                if (binres == -1)
                    printf("Element not found!!");
                else
                    printf("Item is present at index %d", binres);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice !");
                break;
        }
    }
} 
