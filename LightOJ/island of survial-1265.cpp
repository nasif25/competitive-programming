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
//    ios_base::sync_with_stdio(0);

    ll tc, test, i, j, t, d;
    double ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &t, &d);

        if(t%2==1)
        {
            ans=0.0;
        }
        else if(t==0)
        {
            ans=1.0;
        }
        else
        {
            ans=1.0/(double)(t+1.0);
            //cout<<1.0/(double)(t+1.0)<<endl;
        }

        printf("Case %lld: %lf\n", tc, ans);

    }

    return 0;
}

