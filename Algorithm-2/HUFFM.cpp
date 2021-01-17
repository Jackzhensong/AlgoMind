#include<bits/stdc++.h>
using namespace std;
#define N 100
#define M 2*N-1

typedef char *HuffmanCode[2*M];
typedef struct
{
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode, Huffman[M + 1];

typedef struct Node
{
    int weight;
    char c;
    int num;
} WNode, WeightNode[N];

void CreateWeight(char ch[],int *s,WeightNode CW,int *p)
{
      int i,j,k;
      int tag;*p=0;
      
      for(i=0;ch[i]!='\0';i++)
      {
          tag=1;
	      for(j=0;j<i;j++)
	      if(ch[j]==ch[i])
          {
	          tag=0;   break;
           }
          if(tag) {
                  CW[++*p].c=ch[i];
                  CW[*p].weight=1;
                  for(k=i+1;ch[k]!='\0';k++)
                      if(ch[i]==ch[k])
                      CW[*p].weight++;
                      }
          }
                  *s=i;
}

void CreateHuffmanTree(Huffman ht,WeightNode w,int n)
{
     int i,j;
     int s1,s2;
     for(i=1;i<=n;i++) {
         ht[i].weight =w[i].weight;
         ht[i].parent=0;
         ht[i].LChild=0;
         ht[i].RChild=0;
         }
     for(i=n+1;i<=2*n-1;i++)
     {
         ht[i].weight=0;
         ht[i].parent=0;
         ht[i].LChild=0;
         ht[i].RChild=0;
     }
     for(i=n+1;i<=2*n-1;i++)
     {
         for(j=1;j<=i-1;j++)
         if(!ht[j].parent)
         break;
         s1=j;
      
         for(;j<=i-1;j++)
             if(!ht[j].parent)
             s1=ht[s1].weight>ht[j].weight?j:s1;
             ht[s1].parent=i;
             ht[i].LChild=s1;
         for(j=1;j<=i-1;j++)
             if(!ht[j].parent)
             break;
             s2=j;
         
     for(;j<=i-1;j++)
         if(!ht[j].parent)
         s2=ht[s2].weight>ht[j].weight?j:s2;
         ht[s2].parent=i;
         ht[i].RChild=s2;
         ht[i].weight=ht[s1].weight+ht[s2].weight;
         }
}

void CrtHuffmanNodeCode(Huffman ht,char ch[],HuffmanCode h,WeightNode weight,int m,int n)
{
     int i,c,p,start;
     char *cd;
     cd=(char *)malloc(n*sizeof(char));
     cd[n-1]='\0';
     for(i=1;i<=n;i++)
     {
         start=n-1; 
         c=i;
         p=ht[i].parent;
         while(p) 
         {
             start--;
             if(ht[p].LChild==c)
                 cd[start]='0';
             else 
                 cd[start]='1';
             c=p;
             p=ht[p].parent;
         }
         weight[i].num=n-start; 
         h[i]=(char *)malloc((n-start)*sizeof(char));
         strcpy(h[i],&cd[start]);
     }
     free(cd);
     system("pause"); 
}

void CrtHuffmanCode(char ch[],HuffmanCode h,HuffmanCode hc,WeightNode weight,int n,int m)
{
     int i,k;
     for(i=0;i<m;i++)
     { 
         for(k=1;k<=n;k++)
             if(ch[i]==weight[k].c)
             break;
         hc[i]=(char *)malloc((weight[k].num)*sizeof(char));
         strcpy(hc[i],h[k]); 
     }
}

void TrsHuffmanTree(Huffman ht,WeightNode w,HuffmanCode hc,int n,int m)
{
     int i=0,j,p;
     printf("\n");
     while(i<m)
     {
         p=2*n-1;
         for(j=0;hc[i][j]!='\0';j++)
         { 
             if(hc[i][j]=='0')
                 p=ht[p].LChild;
             else
                 p=ht[p].RChild;
         }
         printf("%c",w[p].c); 
         i++; 
     }
}

void FreeHuffmanCode(HuffmanCode h,HuffmanCode hc,int n,int m)
{
     int i;
     for(i=1;i<=n;i++)
     free(h[i]);
     for(i=0;i<m;i++)
    
     free(hc[i]);
}
 void main()
 {
     int i,n=0; 
     int m=0; 
     char ch[N]; 
     Huffman ht; 
     HuffmanCode h,hc; 
     WeightNode weight;
     printf(" :");
     gets(ch); 
     CreateWeight(ch,&m,weight,&n); 
     printf("\n Node ");
     for(i=1;i<=n;i++) 
         printf("%c ",weight[i].c);
     printf("\nWeight ");
     for(i=1;i<=n;i++)
         printf("%d ",weight[i].weight);
     CreateHuffmanTree(ht,weight,n); 
     printf("\n\n");
     printf("\ti\tweight\tparent\tLChild\tRChild\n");
     for(i=1;i<=2*n-1;i++) 
     printf("\t%d\t%d\t%d\t%d\t%d\n",i,ht[i].weight,ht[i].parent,ht[i].LChild,ht[i].RChild);
     CrtHuffmanNodeCode(ht,ch,h,weight,m,n); 
     printf(" \n"); 
         printf("\t%c:",weight[i].c);
         printf("%s\n",h[i]); 
     }
     CrtHuffmanCode(ch,h,hc,weight,n,m); 
     printf("\n"); 
     for(i=0;i<m;i++)
         printf("%s",hc[i]);
     printf("\n"); 
     system("pause");
     TrsHuffmanTree(ht,weight,hc,n,m); 
     FreeHaffmanCode(h,hc,n,m);
     printf("\n");
     system("pause");
 }
