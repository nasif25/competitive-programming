#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)

int main()
{
    int i=1,t;

    double r,l,ca,sa,dif;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%lf",&r);

        l=2*r;
        sa=l*l;
        ca=pi*r*r;
        dif=sa-ca+.000000001;

        printf("Case %d: %.2lf\n",i,dif);

        i++;
    }
 return 0;
}
