#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[65];
ll dp[65][65];

ll solve(ll i, ll j)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]!=s[j])
    {
        return dp[i][j]=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
    }
    else
    {
        return dp[i][j]=1+solve(i+1,j-1)+solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
    }
}

int main()
{
    ll t, test, l, ans;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf(" %s",s);

        l=strlen(s);

        memset(dp,-1,sizeof(dp));

        ans=solve(0,l-1);

        printf("Case %lld: %lld\n",t,ans);
    }

    return 0;
}

