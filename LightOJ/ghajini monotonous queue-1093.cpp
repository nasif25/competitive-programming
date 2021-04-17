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

ll ar[100005];
deque<pll> hi, lo;
//vector<ll> a, b;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
    ll tc, test, n, d, i, j, k, l, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &d);

        ans=0;

        for(k=1; k<=n; k++)
        {
            scanf("%lld", &ar[k]);
        }
        for(k=1, i=1; k<=n; k++)
        {
            if(lo.empty())
            {
                lo.push_front(pll(ar[k], k));
            }
            else
            {
                while(lo.front().uu>=ar[k])
                {
                    lo.ppf();
                    if(lo.empty())
                        break;
                }
                lo.push_front(pll(ar[k], k));
            }

            if(hi.empty())
            {
                hi.push_front(pll(ar[k], k));
            }
            else
            {
                while(hi.front().uu<=ar[k])
                {
                    hi.ppf();
                    if(hi.empty())
                        break;
                }
                hi.push_front(pll(ar[k], k));
            }

            if(k-i+1==d)
            {
                ans=max(ans, hi.back().uu-lo.back().uu);
//                a.pb(lo.back().uu);
//                b.pb(hi.back().uu);

                for(j=0; j<lo.size(); j++)
                {
                    if(lo[j].vv==i)
                    {
                        lo.erase(lo.begin()+j);
                        break;
                    }
                }
                for(j=0; j<hi.size(); j++)
                {
                    if(hi[j].vv==i)
                    {
                        hi.erase(hi.begin()+j);
                        break;
                    }
                }
                i++;
            }

        }
        //cout<<i<<" "<<k<<endl;
//        for(l=0; l<a.size(); l++)
//            cout<<a[l]<<" "<<b[l]<<endl;

        printf("Case %lld: %lld\n", tc, ans);

        lo.clear();
        hi.clear();
//        a.clear();
//        b.clear();
    }

    return 0;
}

