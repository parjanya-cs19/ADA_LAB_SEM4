#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milli_seconds)
{

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int c=1;
    while(c==1)
    {
        int n = 0, choice, key;
        clock_t start, end;
        printf("\nEnter the size of Array : ");
        scanf("%d", &n);
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            arr[j] = (rand() % 100000) + 1;
            printf("%4d", arr[j]);
        }
        printf("\nMenu\n1. Insertion Sort\n2. Exit\nEnter the choice from menu : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = clock();
            n = sizeof(arr) / sizeof(arr[0]);
            insertionSort(arr, n);
            end = clock();
            printf("Sorted array: \n");
            printArray(arr, n);
            printf("Time taken: %f ms\n", (double)(end - start) / CLK_TCK * 1000);
            break;
        case 2:
            c=0;
            exit(0);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
}
