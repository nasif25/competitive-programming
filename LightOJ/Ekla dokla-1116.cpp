#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long i=1,t,j,w,check,track;

    scanf("%lld",&t);

    while(i<=t)
    {
        scanf("%lld",&w);

        if(w%2!=0)
        {
            printf("Case %lld: Impossible\n",i);
            i++;
            continue;
        }

        check=w/2;

        for(j=2; j<=check; j+=2)
        {
            if(w%j==0)
            {
                track=w/j;
                if(track%2!=0)
                {
                    printf("Case %lld: %lld %lld\n",i,track,j);
                    break;
                }
            }
        }
        if(j>check)
            printf("Case %lld: Impossible\n",i);
        i++;
    }
    return 0;
}
