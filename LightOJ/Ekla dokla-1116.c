#include <bits\stdc++.h>
using namespace std;

int main()
{
    unsigned long long i=1,t,m,n,j,w,check,track;
    double k;
    scanf("%lld",&t);

    while(i<=t)
    {
        scanf("%lld",&w);

        if(w%2!=0)
        {
            printf("Case %lld: Impossible\n");
            i++;
            continue;
        }

        k=sqrt((double)w);

        check=(long long)k;

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
        i++;
    }
    return 0;
}
