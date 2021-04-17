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
    ll tc, test;

    double x, y, c, w, m, n, mid, i, j, p, q, a, b;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lf %lf %lf", &x, &y, &c);

        w=min(x, y);
        i=0.0;
        j=w;
        while(1)
        {
            mid=(i+j)/2.0;
            m=sqrt(x*x-mid*mid);
            n=sqrt(y*y-mid*mid);

            p=(x*n)/(m+n);
            q=y-((y*n)/(m+n));

            a=sqrt(p*p-c*c);
            b=sqrt(q*q-c*c);

            if(fabs(mid-(a+b))<0.00000001)
                {
                    w=mid;
                    break;
                }
            else if((a+b)>mid)
            {
                i=mid;
            }
            else
            {
                j=mid;
            }
        }
        printf("Case %lld: %.9lf\n", tc, w);
    }
    return 0;
}
