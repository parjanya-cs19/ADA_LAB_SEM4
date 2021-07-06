#include<stdio.h>
int cost[10][10],vis[10],vt[10],et[10][2],u,v,e,n,sum=0,exclud,prevu=0,prevv=0;
void prims()
{
    int x=1;
    if(exclud!=1)
        vt[x]=1;
    else
        vt[x]=2;
    int min,k,m,j;
    vis[1]=1;
    for(int i=1;i<n;i++)
    {
        min=999;
        j=x;
        while(j>0)
        {
            k=vt[j];
            for(m=2;m<=n;m++)
            {
                if(cost[k][m]<min&&vis[m]==0&&cost[k][m]!=0)
                {
                    min=cost[k][m];
                    u=k;
                    v=m;
                }
            }
            j--;
        }
        if(u!=v&&prevu!=u&&prevv!=v&&u!=exclud)
        {
            vt[++x]=v;
            et[i][0]=u;
            et[i][1]=v;
            e++;
            vis[v]=1;
            sum=sum+cost[u][v];
            prevu=u;
            prevv=v;
        }

    }
}
void main()
{
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    printf("Enter 999 for infinity:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Node not to be visited:\n");
    scanf("%d",&exclud);
    vis[exclud]=1;


    prims();
    printf("Visited Nodes:\n");
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1&&i!=exclud)
        {
            printf("%d \t",i);
        }
    }
    
    printf("\nCOST: %d\n",sum);
    printf("\nEdges :\n");
    for(int i=1;i<=e;i++)
    {
        if(et[i][0]!=et[i][1])
        printf("%d  -  %d\n",et[i][0],et[i][1]);
    }
}
