#include <bits/stdc++.h>
using namespace std;
#define ll long long
char a[51],b[51],c[51];
ll n, dp[51][51][51],u,v,w;

ll lcs(ll i, ll j, ll k)
{
    if(i==u || j==v || k==w)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];

    ll p,q,r;
    p=q=r=0;
    //cout<<a[i]<<" "<<i<<" "<<b[j]<<" "<<j<<" "<<c[k]<< " "<<k<<endl;
    if(a[i]==b[j] && a[i]==c[k])
    {
        p=lcs(i+1,j+1,k+1)+1;

    }
    else
    {
        p=lcs(i+1,j,k);
        q=lcs(i,j+1,k);
        r=lcs(i,j,k+1);
    }
    return dp[i][j][k]=max(p,max(q,r));
}
int main()
{
    ll t, test, ans;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf(" %s %s %s",a,b,c);
        memset(dp,-1,sizeof(dp));
        u=strlen(a);
        v=strlen(b);
        w=strlen(c);

        ans=lcs(0,0,0);

        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

