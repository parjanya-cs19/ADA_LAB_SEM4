#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int c = 1;
    while (c == 1)
    {
        int n = 0, choice, key;
        clock_t start, end;
        printf("\nEnter the size of Array : ");
        scanf("%d", &n);
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            arr[j] = (rand() % 100000) + 1;
        }
        printf("Given array is \n");
        printArray(arr, n);
        printf("\nMenu\n1. Insertion Sort\n2. Exit\nEnter the choice from menu : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = clock();
            int arr_size = sizeof(arr) / sizeof(arr[0]);
            mergeSort(arr, 0, arr_size - 1);
            end = clock();
            printf("\nSorted array is \n");
            printArray(arr, arr_size);
            printf("Time taken: %f ms\n", (double)(end - start) / CLK_TCK * 1000);
            break;
        case 2:
            c = 0;
            exit(0);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
}
