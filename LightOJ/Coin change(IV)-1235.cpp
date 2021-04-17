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
set <ll> v;
set<ll> :: iterator it;
map<ll, bool> mp;

void dp1(ll pos, ll n, ll sum)
{
    if(pos>n)
    {
        v.insert(sum);
        return;
    }

    ll i;

    for(i=0; i<=2; i++)
    {
        dp1(pos+1, n, sum+a[pos]*i);
    }
}
void dp2(ll pos, ll n, ll sum)
{
    if(pos>n)
    {
        mp[sum]=1;
        return;
    }

    ll i;

    for(i=0; i<=2; i++)
    {
        dp2(pos+1, n, sum+a[pos]*i);
    }
}

int main()
{
    ll tc, test, n, k, i, z;
    bool f;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &k);

        for(i=1; i<=n; i++)
            scanf("%lld", &a[i]);

        dp1(1, n/2, 0);
        dp2((n/2)+1, n, 0);

        //cout<<1<<" " <<n/2<<" "<<n<<endl;
        f=0;

        for(it=v.begin(); it!=v.end(); it++)
        {
            //cout<<z<<" "<<*it<<" "<<k-*it<<" "<<mp[k-*it]<<endl;
            if(mp[k-*it]==1 || *it==k)
            {
                f=1;
                break;
            }

        }

        if(f==1)
            printf("Case %lld: Yes\n", tc);
        else
            printf("Case %lld: No\n", tc);

        v.clear();
        mp.clear();
    }

    return 0;
}

