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
set<ll> mp;
set<ll>::iterator it;
ll tc, n, w, k;
ll a[50001];

ll solve(ll pos)
{
    if(pos>=k)
        return 0;

    ll i, fin, t1=0;

    for(i=pos;i<k;)
    {
        fin=a[i]+w;
        t1++;
        for(;i<k && a[i]<=fin;i++)
            {
            }
    }

    return t1;
}

int main()
{
    ll test, x, i, y, ans;

    scanf("%lld", &test);

    for(tc=1;tc<=test;tc++)
    {
        scanf("%lld %lld", &n, &w);

        for(i=0;i<n;i++)
        {
            scanf("%lld %lld", &x, &y);
            mp.insert(y);
        }

        for(it=mp.begin(), k=0;it!=mp.end();it++,k++)
        {
            a[k]=*it;
        }

        ans=solve(0);

        printf("Case %lld: %lld\n", tc, ans);
        mp.clear();
    }

    return 0;
}


