#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 100000007
ll dp[51][1001];
int coin[51],num[51],n;

ll call(int i, int x)
{
    if(i>=n)
    {
        if(x==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][x]!=-1)
        return dp[i][x];
    ll ret1=0,ret2=0,j;
//    temp=num[i];
    if(x-coin[i]>=0)
        {

            for(j=1;j<=num[i];j++)
                {
                    if(x-j*coin[i]>=0)
                        ret1+=call(i+1,x-j*coin[i]);
                    else
                        break;
                }
            //cout<<"i= "<<i<<" x= "<<x<<" coin[i]= "<<coin[i]<<" num[i]= "<<num[i]<<endl;
        }
    ret2=call(i+1,x);
    //cout<<"ret1= "<<ret1<<" ret2= "<<ret2<<endl;
    return dp[i][x]=(ret1%mod+ret2%mod)%mod;
}

int main()
{
    int t,test,k,i,j;
    ll ans;
    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&coin[i]);
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        ans=call(0,k);

        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
