#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 30005
deque <pll> dq;
ll a[limit], ans;

void solve(ll n)
{
    ll i, j, u, v, lp;
    pll x;

    for(i=1; i<=n; i++)
    {
        ans=max(ans, a[i]);

        if(dq.empty())
        {
            dq.pb(pll(a[i], 1));
        }
        else
        {
            x=*(dq.end()-1);
            u=x.uu;
            v=x.vv;

            if(a[i]>=u)
            {
                dq.pb(pll(a[i], i));
            }
            else
            {
                while(a[i]<u)
                {
                    lp=v;
                    dq.ppb();
                    ans=max(ans, u*(i-v));

                    if(dq.empty())
                        break;

                    x=*(dq.end()-1);
                    u=x.uu;
                    v=x.vv;
                }
                dq.pb(pll(a[i],lp));
            }
        }
    }

    while(!dq.empty())
    {
        x=dq[0];
        u=x.uu;
        v=x.vv;

        ans=max(ans, u*(n-v+1));
        //cout<<u<<" "<<v<<" "<<j<<" "<<ans<<endl;
        dq.ppf();
    }
}


int main()
{
    ll tc, test, i , n;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);
        ans=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &a[i]);
        }
        solve(n);

        printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}
