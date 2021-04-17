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

double ar[100005];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//      ios_base::sync_with_stdio(0);

    ll tc, test, i, n, x;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        ar[1]=1.0;

        for(i=2; i<=n; i++)
        {
            ar[i]=((double)(i-1)/(n-(i-1)))+ar[i-1]+1.0;
        }
        printf("Case %lld: %.9lf\n", tc, ar[n]);
    }

    return 0;
}
