#include <stdio.h>
int main()
{
    int t,caseno=0;
    unsigned long long sum,n,m;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);

        sum=m*n/2;
        printf("Case %d: %lld\n",++caseno,sum);
    }
    return 0;
}

