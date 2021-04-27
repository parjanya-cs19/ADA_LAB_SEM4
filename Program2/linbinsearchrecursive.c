#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int linearSearch(int array[], int size, int key)
{
    int location, i, j;
    if (array[size] == key)
    {
        return size;
    }
    else if (size == -1)
    {
        return -1;
    }
    else
    {
        return (location = linearSearch(array, size - 1, key));
    }
}

void bubble_sort(int arrb[], int size)
{

    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arrb[i] > arrb[j])
            {
                temp = arrb[i];
                arrb[i] = arrb[j];
                arrb[j] = temp;
            }
        }
    }
    for (int j = 0; j < size; j++)
    {
        printf("%4d\n", arrb[j]);
    }
}

int binarySearch(int arrb[], int lo, int key, int hi)
{
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (arrb[mid] == key)
    {
        printf("Key found\n");
    }
    else if (arrb[mid] > key)
    {
        binarySearch(arrb, lo, mid - 1, key);
    }
    else if (arrb[mid] < key)
    {
        binarySearch(arrb, mid + 1, hi, key);
    }
}

int main()
{
    
    clock_t start, end;
    int n = 0, choice, key;
    printf("\nEnter the size of Array : ");
    scanf("%d", &n);
    int arr[n], arrl[n], arrb[n];
    for (int j = 0; j < n; j++)
    {
        arr[j] = (rand() % 200) + 1;
        printf("%4d\n", arr[j]);
    }
    for (int i = 0; i < n; i++)
    {
        arrl[i] = arr[i];
        arrb[i] = arr[i];
    }
    for (;;)
    {
        printf("\nMenu\n1. Linear Search\n2. Binary Search\n3.Exit\nEnter the choice from menu : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be searched : ");
            scanf("%d", &key);
            start = clock();
            int linres = linearSearch(arrl, n, key);
            if (linres == -1)
                printf("Element not found!!");
            else
                printf("Item is present at index %d", linres);
            end = clock();
            double timea = (end - start);
            printf("\nTime Taken is %.10f sec", timea);

            break;
        case 2:
            start = clock();
            printf("\nEnter the element to be searched : ");
            scanf("%d", &key);
            bubble_sort(arrb, n);
            binarySearch(arrb, 0, key, n);
            end = clock();
            double timeb = (end - start);
            printf("\nTime Taken is %.10f sec", timeb);

            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
}