
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

double a[101], dp[101][7];
bool vis[101][7];
ll n;

double solve(ll pos, ll dice)
{
    if(pos==n)
        return dp[pos][dice]=a[pos];

    if(vis[pos][dice]!=0)
        return dp[pos][dice];

    vis[pos][dice]=1;

    ll i, num=0;
    double sum=0.0;

    for(i=1;i<=6;i++)
    {
        if(pos+i<=n)
        {
            sum+=solve(pos+i,i);
            num++;
            //cout<<pos<<" "<<sum<<" "<<num<<endl;
        }
    }

    return dp[pos][dice]=a[pos]+(sum/(double)num);
}

int main()
{
    ll i, j, k, t, test;

    double ans;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%lf", &a[i]);
        }

        memset(vis, 0, sizeof(vis));
        ans=solve(1,1);

        printf("Case %lld: %lf\n", t, ans);
    }

    return 0;
}
