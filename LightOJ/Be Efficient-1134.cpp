#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define ppf pop_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

ll a[100005];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
    ll test, tc, n, m, ans, cum, v, i;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &m);

        ans=cum=0;
        memset(a, 0, sizeof(a));

        for(i=0; i<n; i++)
        {
            scanf("%lld", &v);

            cum+=v;

            v=cum%m;

            a[v]++;
            ans+=a[v]-1;
            if(v==0)
                ans++;
        }
        printf("Case %lld: %lld\n", tc, ans);
    }

    return 0;
}

