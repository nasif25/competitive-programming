#include <bits/stdc++.h>
using namespace std;
int a[21][4],dp[21][4],n;

int call(int i, int j)
{
    if(i==n+1)
        return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret1=0,ret2=0;
    if(j==1)
    {
        ret1=a[i][j]+call(i+1,j+1);
        ret2=a[i][j]+call(i+1,j+2);
    }
    else if(j==2)
    {
        ret1=a[i][j]+call(i+1,j-1);
        ret2=a[i][j]+call(i+1,j+1);
    }
    else if(j==3)
    {
        ret1=a[i][j]+call(i+1,j-2);
        ret2=a[i][j]+call(i+1,j-1);
    }
    //cout<<ret1<<" "<<ret2<<" "<<i<<" "<<j<<endl;
    return dp[i][j]=min(ret1,ret2);
}

int main()
{
    int t, test, i, j, ans;

    scanf("%d",&test);
    a[0][1]=a[0][2]=a[0][3]=0;
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=3;j++)
            scanf("%d",&a[i][j]);
        }
        ans=min(min(call(1,1),call(1,2)),call(1,3));

        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
