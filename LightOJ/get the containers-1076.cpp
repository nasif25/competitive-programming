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

int main()
{
    ll tc, test, n, m, c[1005], i, j, sum, hi, k, p, mid, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &m);

        c[0]=sum=hi=0;

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &c[i]);

            sum+=c[i];
            hi=max(hi, c[i]);
        }

        i=hi;
        j=sum;

        while(i<=j)
        {
            mid=(i+j)/2;
            sum=p=0;
            for(k=1; k<=n; k++)
            {
                sum+=c[k];
                if(sum==mid)
                {
                    p++;
                    sum=0;
                }
                else if(sum>mid)
                {
                    sum=c[k];
                    p++;
                }
            }

            if(sum>0)
                p++;

            //cout<<p<<" "<<m<<" "<<mid<<endl;

            if(p>m)
                i=mid+1;
            else if(p<=m)
            {
                j=mid-1;
                ans=mid;
            }
        }
        printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}

