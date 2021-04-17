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

    double a, b, i, j, r, d, s, x, m, c, ans, l, w;
    char g;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lf %c %lf", &a, &g, &b);

        i=0.0001;
        j=400.0/a;

        while(1)
        {
            m=(i+j)/2.0;

            l=a*m;
            w=b*m;

            d=sqrt(l*l+w*w);
            r=d/2.0;
            c=2.0*asin(w/d);
            s=r*c;
            x=2.0*(l+s);

            if(fabs(400.0-x)<0.00000001)
                {
                    ans=m;
                break;
            }
            else if(400.0>x)
                i=m;
            else
                j=m;
        }
        printf("Case %lld: %.9lf %.9lf\n", tc, ans*a, ans*b);

    }
    return 0;
}

