#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int c1,c2,a1,a2,b1,b2,i=1,t;
    double s,theta,pi=3.1416,r,l;

    scanf("%d",&t);
    while(i<=t)
    {
        scanf("%d %d %d %d %d %d",&c1,&c2,&a1,&a2,&b1,&b2);

        r=sqrt((c1-a1)*(c1-a1)+(c2-a2)*(c2-a2));
        l=sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2))/2;
        theta=2*asin(l/r);

        s=r*theta;

        printf("Case %d: %lf\n",i,s);

        i++;
    }
    return 0;
}
