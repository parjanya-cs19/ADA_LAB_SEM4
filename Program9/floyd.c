#include<stdio.h>

void floyd();

int a[10][10], p[10][10], i,j,k,n;

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

void main()
{
    printf("Enter number of Vertices\n");
    scanf("%d",&n);
    printf("Enter Weighted Graph\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    floyd();
    printf("Cost Matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}
void floyd()
{
for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
        p[i][j]=a[i][j];
   }
}
    for(k=1;k<=n;k++)
    {
      for(i=1;i<=n;i++)
       {
         for(j=1;j<=n;j++)
           {
              p[i][j] = min(p[i][j], p[i][k]+p[k][j]);
         }
      }
   }
}