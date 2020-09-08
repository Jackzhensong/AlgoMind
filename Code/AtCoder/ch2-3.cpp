#include<iostream>
#include<cstring>
using namespace std;
 
int main (){
  int N;
  cin >>N;
  int t=0;
  for (int i=1;i<3200;i++){
    if (N==i*(i-1)/2) {t=i;break;}
  }
  if (t>0){
    cout << "Yes" << endl;
    cout << t << endl;
    for(int p=0;p<t;p++){
      cout << t-1;
      for(int i=1;i<=(t-1)/2;i++){
        int a=(i-1)*t+p+1;
        int b=(i-1)*t+(p+t-i)%t+1;
        cout<<" "<<a << " "<<b;
      }
      if (t%2==0){
        cout<<" "<<(i-1)*t+p%(t/2)+1;
      }
      cout <<endl;
    }
  }
  else  cout << "No" << endl;
  return 0;
}

int  main()
{
  int n; 
  cin >> n;
  int k = -1;
  for(int i = 1; i < 10000; i++){
    if(i*(i-1)/2 == n) k = i;
  }
  if(k == -1){
    cout << "No" << endl;
    return 0;
  }
  int r = 1;
  vector< vector<int> > v(2*n);
  for(int i = 0; i < k; i++){
    for(int j = i+1; j < k; j++){
      v[i].push_back(r);
      v[j].push_back(r);
      r++;
    }
  }
  cout << "Yes" << '\n' << k << endl;
  for(int i = 0; i < k; i++){
    cout << k-1 << " ";
    for(int j = 0; j < k-1; j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}


int n,x,p=1;
int a[450][450];
 
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=450&&!x;i++)
		if ((i+1)*i==(n<<1)) x=i;
	if (!x) return puts("No"),0;
	puts("Yes");
	printf("%d\n",x+1);
	for (int i=1;i<=x;i++)
		for (int j=1;j<=i;j++,p++)
			a[i][j]=p;
	for (int i=1;i<=x;i++)
	{
		printf("%d",x);
		int xx=i,yy=1;
		while (a[xx][yy]) printf(" %d",a[xx][yy++]);
		--yy;++xx;
		while (a[xx][yy]) printf(" %d",a[xx++][yy]);
		putchar('\n');
	}
	printf("%d",x);
	for (int i=1;i<=x;i++) printf(" %d",a[i][i]);
	putchar('\n');
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define Maxn 10010
 
int n, m, k, Start;
int a[Maxn][Maxn];
 
int main()
{
	scanf("%d", &n); 
    n*=2;
	m=(int)sqrt(n);
	if (m*(m+1)!=n) { puts("No"); return 0; }
	else
	{
		puts("Yes");
		printf("%d\n", k=n/m);
		Start=1;
		for (int s=1; s<=m; s++)
		{
			for (int i=s; i<=m; i++) a[s][i]=Start+i-s;
			for (int i=s+1; i<=k; i++) a[i][s]=a[s][m+s-i+1];
			Start+=(m-s+1);
		}
		for (int i=1; i<=k; i++)
		{
			printf("%d ", m);
			for (int j=1; j<=m; j++) printf("%d ", a[i][j]); puts("");
		}
	}
	
}