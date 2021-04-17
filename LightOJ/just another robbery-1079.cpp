#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define ppf pop_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plf pair<ll, double>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000
ll n;
double p;

struct node
{
    ll m;
    double pr;
} ar[101];

bool comp(node x, node y)
{
    if(x.m<y.m)
        return true;
    else if(x.m==y.m)
    {
        if(x.pr<y.pr)
            return true;
    }

    return false;
}

double dp[102][10101];
bool vis[102][100101];

double solve(ll pos, ll cap)
{
    if(cap<=0)
        return 0.0;
    if(pos>n)
        return (double) inf;

    if(vis[pos][cap]==1)
        return dp[pos][cap];

    vis[pos][cap]=1;

    double p1, p2;

    p1=ar[pos].pr+(1.0-ar[pos].pr)*solve(pos+1, cap-ar[pos].m);

    p2=solve(pos+1, cap);

    return dp[pos][cap]=min(p1, p2);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll tc, test, i, j, ans, sum, b, e, mid;
    double t;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lf %lld", &p, &n);
        sum=ans=0;

        for(i=1; i<=n; i++)
        {
            scanf("%lld %lf", &ar[i].m, &ar[i].pr);
            sum+=ar[i].m;
        }

        sort(ar+1, ar+n+1, comp);
        memset(vis, 0, sizeof(vis));

        b=0, e=sum;
        ans=0;

        while(b<=e)
        {
            mid=(b+e)/2;

            t=solve(1, mid);

            if(t<p)
            {
                ans=max(ans, mid);
                b=mid+1;
            }
            else
                e=mid-1;
        }

        printf("Case %lld: %lld\n", tc, ans);
    }

    return 0;
}

