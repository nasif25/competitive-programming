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

int main()
{
    ll tc, test;

    double l, n, c, theta, s, i, j, arc, chord, r, cnt, t, narc;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lf %lf %lf", &l, &n, &c);

        arc=(1.0+n*c)*l;

        i=s=0.0;
        j=2.0*pi;
        cnt=0;
        if(l>0.0 && n>0.0 && c>0.0)
        {
            while(cnt<=50)
            {
                t=(i+j)/2.0;
                r=(l/2.0)/sin(t/2.0);
                narc=t*r;

                if(fabs(arc-narc)<0.00000001)
                {
                    s=r-sqrt(r*r-(l/2.0)*(l/2.0));
                    //s=r*(1.0-cos(t/2.0));
                    break;
                }
                else if(narc>arc)
                    j=t;
                else
                    i=t;
                cnt++;
            }
        }
        printf("Case %lld: %.9lf\n", tc, s);
    }
    return 0;
}

