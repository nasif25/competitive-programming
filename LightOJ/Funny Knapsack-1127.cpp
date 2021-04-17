#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

ll a[20];
//map<ll, ll> v, mp;
//map<ll, ll> :: iterator it;
vector <ll> v, mp;

void dp1(ll pos, ll n, ll sum)
{
    if(pos>n)
    {
        //v[sum]++;
        v.pb(sum);
        return;
    }

    ll i;

    for(i=0; i<=1; i++)
    {
        dp1(pos+1, n, sum+a[pos]*i);
    }
}
void dp2(ll pos, ll n, ll sum)
{
    if(pos>n)
    {
        //mp[sum]++;
        mp.pb(sum);
        return;
    }

    ll i;

    for(i=0; i<=1; i++)
    {
        dp2(pos+1, n, sum+a[pos]*i);
    }
}

int main()
{
    ll tc, test, n, k, i, sum;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &k);

        for(i=1; i<=n; i++)
            scanf("%lld", &a[i]);

        dp1(1, n/2, 0);
        dp2((n/2)+1, n, 0);

        //cout<<1<<" " <<n/2<<" "<<n<<endl;
        sum=0;
        sort(v.begin(), v.end());
        sort(mp.begin(), mp.end());
        ll z=v.size();

        for(i=0; i<z; i++)
        {
//            cout<<it->uu<<" "<<it->vv<<" "<<k-it->uu<<" "<<mp[k-it->uu]<<endl;
            if(v[i]<=k)
                {
                    sum+=(upper_bound (mp.begin(), mp.end(), k-v[i])-mp.begin());
                }
            else
                break;
        }

        printf("Case %lld: %lld\n", tc, sum);

        v.clear();
        mp.clear();
    }

    return 0;
}

