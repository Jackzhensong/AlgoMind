#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    long long sum1=0,sum2=0;
    scanf("%d",&m);
    int a[m+5];
    for(int i=1;i<=m;i++)
    	scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	if(m==2)
	printf("%d\n",abs(a[1]-a[2]));
	else
	{
	int x=1,y=m;
	int k=(m+1)/2;
	while(x!=k && y!=k)
	{
		if(k<=(m+1)/2)
		{
			if(y!=(m+1)/2)
				sum1=sum1+abs(a[k]-a[y]);
		    k=y;
		    y--;
		}
		else
		{
			if(x!=(m+1)/2)
				sum1=sum1+abs(a[k]-a[x]);
			k=x;
			x++;
		}
	}
	x=1;y=m;
	k=(m+1)/2;
	while(x!=k&&y!=k)
	{
		if(k<(m+1)/2)
		{
			if(y!=(m+1)/2)
			sum2=sum2+abs(a[k]-a[y]);
		    k=y;
		    y--;
		}
		else
		{
			if(x!=(m+1)/2)
			sum2=sum2+abs(a[k]-a[x]);
			k=x;
			x++;
		}
	}
	printf("%lld\n",max(sum1,sum2));
	}
    return 0;
}

//typedef long long ll;
int main(){
    int n;
    long long x[100000+5];
    cin >> n;
    for(int a = 0; a < n; a++) 
        cin >> x[a];
    sort(x, x+n);
    long long ans = 0;
    int a = 0; 
    int b = n-1;
    ans += x[b]-x[a];
    while(a < b){
        if(a+2 == b){
            ans += max(x[b]-x[a+1], x[b-1]-x[a]);
            break;
        }
        ans += x[b]-x[a+1]+x[b-1]-x[a];
        a++; b--;
    }
    cout << ans << endl;
    return 0;
}