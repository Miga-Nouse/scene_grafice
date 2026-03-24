#include <stdio.h>
#include <stdlib.h>
int max(int n, int *arr)
{ int m=arr[0];
    for(int i=1;i<n;i++)
    {if (arr[i]>m)
      m=arr[i];
    }
    return m;
}
int countSort(int n, int *arr, int exp)
{   int *curr=(int*)malloc(10*sizeof(int));
    int *outpurr=(int*)malloc(n*sizeof(int));
      for (int i=0;i<10;i++)
      {curr[i]=0;
      }
      for (int i=0;i<n;i++)
       curr[(arr[i]/exp)%10]++;
      for (int i=1;i<10;i++)
       curr[i]+=curr[i-1];
      for (int i=n-1;i>=0;i--)
      {outpurr[curr[(arr[i]/exp)%10]-1]=arr[i];
       curr[(arr[i]/exp)%10]--;
      }
      for(int i=0;i<n;i++)
       arr[i]=outpurr[i];
       

   free(outpurr);
   free(curr);
}
 void radix(int n,int *arr)
{   int maxVal = max(n, arr);
    for (int exp=1;maxVal/exp>0;exp*=10)
    {countSort(n, arr,exp);}
}
