
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

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//      ios_base::sync_with_stdio(0);
    ll i, n, ans, tc, test;
    double res;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        res=1.0;
        ans=1;
        for(i=n-1; ; ans++,i--)
        {
            res*=(1.0*i)/(1.0*n);
            //cout<<res<<endl;
            if(res<=.5)
                break;
        }

        printf("Case %lld: %lld\n", tc, ans);
    }

    return 0;
}
