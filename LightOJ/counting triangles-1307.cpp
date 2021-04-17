#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000
ll a[2005];

int main()
{
    ll tc, test, i, j, k, n, x, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        for(i=0; i<n; i++)
            scanf("%lld", &a[i]);

        sort(a, a+n);

//        for(i=0; i<n; i++)
//            printf("%lld ", a[i]);
//            cout<<endl<<endl;

        ans=0;

        for(i=0; i<n-2; i++)
        {
            for(j=i+1; j<n-1; j++)
            {
                //cout<<a[lower_bound(a+j+1, a+n, a[i]+a[j])-a]<<endl;
                x=lower_bound(a+j+1, a+n, a[i]+a[j]) - (a+j) - 1;

                //cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<x<<endl;

                ans+= max(0LL,x);
            }
        }

        printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}

