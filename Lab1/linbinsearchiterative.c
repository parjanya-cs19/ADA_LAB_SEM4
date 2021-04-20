#include<stdio.h>
#include<stdlib.h>

int linearSearch(int array[], int size, int val) 
{ 
    for (int i = 0; i < size; i++) 
        if (array[i] == val) 
            return i; 
    return -1; 
} 


int binarySearch(int arry[], int val, int high)
{
    int i, j, temp;
    for (i = 0; i < high; i++)
    {
        for (j = 0; j < (high - i - 1); j++)
        {
            if (arry[j] > arry[j + 1])
            {
                temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
            }
        }
    }
    for(i=0; i< high; i++)
    {
        printf("%4d\n",arry[i]);
    }
    int mid,flag=0,low=0;
    while(low<=high&& flag==0)
    {
        mid=(low+high)/2;
        if(arry[mid]==val)
        {
            flag=1;
        }
        if(val>arry[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==0)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Key found at position %d\n",mid+1);
    }
}

 
int main() 
{
    int n=0, choice, key;
    printf("\nEnter the size of Array : ");
    scanf("%d",&n);
    int arr[n];
    for(int j = 0; j < n; j++)
          {
                  arr[j] = (rand() % 200)+1;
                  printf("%4d\n", arr[j]);
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
                binarySearch(arr, key,n);
                
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice !");
                break;
        }
    }
} 
