#include <bits/stdc++.h>
#define pi acos(-1)

int main()
{
    int i=1,t;

    double r1,r2,h,p,r3,h1,v1,v2,x,d;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);

        d=r1-r2;

        x=p*d/h;
        r3=r2+x;

        h1=h*r3/d;

        v1=pi*h1*r3*r3/3;
        v2=pi*(h1-p)*r2*r2/3;

        printf("Case %d: %.9lf\n",i,v1-v2);

        i++;
    }
    return 0;
}
