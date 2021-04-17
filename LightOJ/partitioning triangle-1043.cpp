#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define msz 4
#define cn 3
#define rn 3
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

int main()
{
    double ab, bc, ac, r, beg, fin, adp, ad, ae, de, tri, p, x, y, div;
    ll tc, test;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &r);

        p=(ab+ac+bc)/2;
        tri=sqrt(p*(p-ab)*(p-ac)*(p-bc));

        beg=0.0;
        fin=ab;

        adp=0;
        ad=(beg+fin)/2.0;

        while(fabs(ad-adp)>0.000000001)
        {
            ae=(ac*ab)/ad;
            de=(ad*bc)/ab;

            x=de*ad;
            y=(bc+de)*(ab-ad);

            div=x/y;

            if(div>r)
            {
                fin=ad;
                adp=ad;
            }
            else
            {
                beg=ad;
                adp=ad;
            }
            ad=(beg+fin)/2.0;
        }
        printf("Case %lld: %.9lf\n", tc, ad);
    }

    return 0;
}
