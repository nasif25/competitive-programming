#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

ll a[2005], ans;
char s[2005];
deque <pll> dq;

void solve(ll n)
{
    ll i, u, v, lp;
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
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll tc, test, i, j, m, n;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &m, &n);

        ans=0;

        for(i=1; i<=n; i++)
            a[i]=0;

        for(i=1; i<=m; i++)
        {
            scanf(" %s", s);

            for(j=0; j<n; j++)
            {
                if(s[j]=='0')
                    a[j+1]++;
                else
                    a[j+1]=0;
            }
            solve(n);
        }
        printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}
