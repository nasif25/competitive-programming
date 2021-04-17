#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define msz 4
#define cn 3
#define rn 3
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

char s[1010];
ll dp[1005][1005];

ll solve(ll i, ll j)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll p1, p2;

    p1=p2=LLONG_MAX;

    if(s[i]==s[j])
    {
        p1=solve(i+1,j-1);
        //cout<<s[i]<<" "<<s[j]<<" "<<p1<<endl;
    }
    else
    {
        p1=solve(i+1,j)+1;
        p2=solve(i,j-1)+1;
        //cout<<s[i]<<" "<<s[j]<<" "<<p1<<" "<<p2<<endl;
    }
    return dp[i][j]=min(p1,p2);
}

int main()
{
    ll t, test, ans;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf(" %s", s);
        //cout<<s<<endl;
        memset(dp, -1, sizeof(dp));

        ans=solve(0,strlen(s)-1);

        printf("Case %lld: %lld\n", t, ans);
    }
    return 0;
}
