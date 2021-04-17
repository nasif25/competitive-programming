#include <stdio.h>

int main()
{
    unsigned long long t,n,k,i,j,temp,s,x;

    scanf("%lld",&t);

    for(i=1; i<=t; i++)
    {
        scanf("%llu",&n);
        scanf("%llu",&k);

        if(k>n)
            printf("Case %llu: 0\n",i);

        else if(k<=n)
        {
            temp=1,x=n;
            for(j=1,s=1; j<=k; j++,s++,x--)
            {
                temp=temp*x*x;
                temp=temp/s;
            }
            printf("Case %llu: %llu\n",i,temp);
        }
    }
    return 0;
}
