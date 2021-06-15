#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
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
        }
        n = sizeof(arr) / sizeof(arr[0]);
        printf("Unsorted Array\n");
        printArray(arr, n);
        printf("\nMenu\n1. Insertion Sort\n2. Exit\nEnter the choice from menu : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = clock();
            n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n - 1);
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