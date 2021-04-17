#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t, test,r,c,v,x,d;
    int i,j;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld",&r,&c);
        v=0;

        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%lld",&x);
                d=(r-i)+(c-j);

                if(d%2==1)
                {
                    v=v^x;
                }
            }
        }

        if(v>0)
            printf("Case %lld: win\n",t);
        else
            printf("Case %lld: lose\n",t);

    }
    return 0;
}
