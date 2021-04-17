#include <bits/stdc++.h>
int main()
{
    int i=1,c;

    double v1,v2,v3,a1,a2,s1,s2,t1,t2,b;

    scanf("%d",&c);

    while(i<=c)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

        t1=v1/a1;
        t2=v2/a2;

        s1=v1*t1-.5*a1*t1*t1;
        s2=v2*t2-.5*a2*t2*t2;

        if(t1<t2)
            t1=t1+t2-(t2=t1);

        b=v3*t1;

        printf("Case %d: %lf %lf\n",i,(s1+s2),b);

        i++;
    }
    return 0;
}
