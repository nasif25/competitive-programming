#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LIMIT 1000000000000000000
int main()
{
    ll t, test, i, j, x, v, n, m;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld", &n, &x);

        m=1;
        v=x;

        while(v%n!=0)
        {
           v=v%n;
           v=v*10+x;
           m++;
           if(v>LIMIT)
           {
               v=v%n;
               if(v==0)
                break;
               v=v*10+x;
               m++;
           }
        }

        printf("Case %lld: %lld\n",t, m);
    }
    return 0;
}

