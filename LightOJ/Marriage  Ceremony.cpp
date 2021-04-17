#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;

int ar[17][17],dp[17][17],n;
bool take[17];

int call(int x,int y,int s)
{
    if(x>n || y>n)
            return s;

    if(dp[x][y]!=-1)
        return dp[x][y];

    int j,hi=0;

    for(j=1;j<=n;j++)
    {
        if(take[j]==0)
        {
            take[j]=1;
            //cout<<"a "<<x<<" "<<j<< " "<<s<<" "<<hi<<endl;
            hi=max(hi,call(x+1,j,s+ar[x][j]));
            //cout<<"b "<<x<<" "<<j<< " "<<s<<" "<<hi<<endl;
            take[j]=0;
        }
        //else cout<<x<<" "<<j<<endl;
    }
    return hi;
}

int main()
{
    int t,i,j,test,ans;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&ar[i][j]);
        }
        memset(dp,-1,sizeof(dp));
        memset(take,0,sizeof(take));
        ans=call(1,1,0);

        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
