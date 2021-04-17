#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[201][201],dp[201][201],k,n;
int call(int i, int j, int x)
{
    if(i==k)
    {
        return a[i][1];
    }
    if(i>k || (i<=n && j>i)||(i>n && j>(n+n-i) || j<1))
       {
           return 0;
       }
    if(dp[i][j]!=-1)
        return dp[i][j];

      int ret1,ret2;

      if(i<n)
        {
            ret1=a[i][j]+call(i+1,j,x);
            ret2=a[i][j]+call(i+1,j+1,x);
        }
    else
        {
            ret1=a[i][j]+call(i+1,j-1,x);
            ret2=a[i][j]+call(i+1,j,x);
        }
       return dp[i][j]=max(ret1,ret2);
}


int main()
{
    int t,test,j,i,s,ans;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                scanf("%d",&a[i][j]);
        }
        k=n+n-1;
        for(i=n+1;i<=k;i++)
        {
            s=n+n-i;
            for(j=1;j<=s;j++)
                scanf("%d",&a[i][j]);
        }
        ans=call(1,1,0);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

