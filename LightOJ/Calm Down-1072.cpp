#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1)

int main()
{
    int i=1,t,n;

    double theta,bigr,litr;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%lf %d",&bigr,&n);

        theta=pi/(double)n;

        theta=sin(theta);

        litr=(bigr*theta)/(1+theta);

        printf("Case %d: %.9g\n",i,litr);

        i++;
    }
    return 0;
}
