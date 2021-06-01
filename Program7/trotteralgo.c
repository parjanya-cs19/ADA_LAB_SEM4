#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;

void delay(int milli_seconds)
{

	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds)
		;
}

int searchArr(int a[], int n, int mobile)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == mobile)
			return i + 1;
	}
}

int getMobile(int a[], bool dir[], int n)
{
	int mobile_prev = 0, mobile = 0;
	for (int i = 0; i < n; i++)
	{
		if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0)
		{
			if (a[i] > a[i - 1] && a[i] > mobile_prev)
			{
				mobile = a[i];
				mobile_prev = mobile;
			}
		}

		if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1)
		{
			if (a[i] > a[i + 1] && a[i] > mobile_prev)
			{
				mobile = a[i];
				mobile_prev = mobile;
			}
		}
	}

	if (mobile == 0 && mobile_prev == 0)
	{
		return 0;
	}
	else
	{
		return mobile;
	}
}

int printOnePerm(int a[], bool dir[], int n)
{
	int mobile = getMobile(a, dir, n);
	int pos = searchArr(a, n, mobile);
	int temp1, temp2;

	if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)
	{
		temp1 = a[pos - 1];
		a[pos - 1] = a[pos - 2];
		a[pos - 2] = temp1;
	}
	else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
	{
		temp2 = a[pos - 1];
		a[pos - 1] = a[pos];
		a[pos] = temp2;
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] > mobile)
		{
			if (dir[a[i] - 1] == LEFT_TO_RIGHT)
			{
				dir[a[i] - 1] = RIGHT_TO_LEFT;
			}
			else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
			{
				dir[a[i] - 1] = LEFT_TO_RIGHT;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf(" ");
}

int fact(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++)
	{
		res = res * i;
	}
	return res;
}

void printPermutation(int n)
{
	int a[n];
	bool dir[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		printf("%d,", a[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		dir[i] = RIGHT_TO_LEFT;
	}

	for (int i = 1; i < fact(n); i++)
	{
		printOnePerm(a, dir, n);
	}
}

int main()
{
	int c = 1;
	while (c == 1)
	{
		int n = 0, choice, key;
		clock_t start, end;
		printf("\nEnter the number of elements: ");
		scanf("%d", &n);
		printf("\nMenu\n1. Run Algorithm\n2. Exit\nEnter the choice from menu : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			start = clock();
			printPermutation(n);
			end = clock();
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
