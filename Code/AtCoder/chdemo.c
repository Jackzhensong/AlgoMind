#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int main()
{
  int N,*x,*y,*h,i,j,k,init;
  int H,C,a,b,c;
  scanf("%d",&N);
  x = (int *)malloc(sizeof(int)*N);
  y = (int *)malloc(sizeof(int)*N);
  h = (int *)malloc(sizeof(int)*N);
  for(i=0; i<N; i++)
    scanf("%d%d%d",&x[i],&y[i],&h[i]);
  for(i=0; i<=100; i++)
    for(j=0; j<=100; j++)
    {
      init = 0;
      while(h[init]==0)
        init++;
      H = h[init] + abs(i-x[init]) + abs(j-y[init]);
      for(k=0; k<N; k++)
      {
        C = h[k] + abs(i-x[k]) + abs(j-y[k]);
        if(h[k]==0)
        {
          if(H - abs(i-x[k]) - abs(j-y[k]) >0)
            break;
        }
        else
        {
          if(H!=C)
            break;
        }
      }
      if(k==N)
      {
        a = i;b = j;c = H;
      }
    }     
  printf("%d %d %d\n",a,b,c);
  return 0;
}