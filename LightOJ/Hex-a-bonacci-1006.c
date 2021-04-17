#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,cases,caseno = 0 ,i,j;
    unsigned long long num[10003];
    scanf("%d", &cases);
    while( cases-- )
    {
        for(i=0; i<6; i++)
            scanf("%lld",&num[i]);

        scanf("%d",&n);

        for(i=6; i<=n; i++)
        {
            num[i]=0;
            for(j=i-1; j>=i-6; j--)
                num[i]+=num[j]%10000007;
        }
        printf("Case %d: %lld\n", ++caseno, num[n] % 10000007);
    }
    return 0;
}
