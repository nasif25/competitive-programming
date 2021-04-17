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
        n++;
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &c[i]);

            sum+=c[i];
            hi=max(hi, c[i]);
        }

        i=hi;
        j=sum;
        m++;
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

        sum=p=0;
        for(k=1; k<=n; k++)
        {
            if(n-k+1>m-p)
            {
                sum+=c[k];

                if(sum==ans)
                {
                    p++;
                    printf("%lld\n", sum);
                    sum=0;
                }
                else if(sum>ans)
                {
                    p++;
                    printf("%lld\n", sum-c[k]);
                    sum=c[k];
                }
            }
            else
            {
                if(sum>0)
                {
                    if(c[k]+sum>ans)
                    {
                        printf("%lld\n", sum);
                        p++;
                        if(c[k]==ans)
                        {
                            printf("%lld\n", c[k]);
                            sum=0;
                            p++;
                        }
                        else
                        {
                            sum=c[k];
                        }
                    }
                    else
                    {
                        printf("%lld\n", sum+c[k]);
                        p++;
                        sum=0;
                    }
                }
                else
                {
                    printf("%lld\n", c[k]);
                    p++;
                }
            }
        }

        if(sum>0)
            printf("%lld\n",sum);
    }
    return 0;
}

