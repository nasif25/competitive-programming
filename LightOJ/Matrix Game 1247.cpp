#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll test,t,n,m,i,j,p,b,nim;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld",&n,&m);

        nim=0;
        for(i=0;i<n;i++)
        {
            b=0;
            for(j=0;j<m;j++)
            {
                scanf("%lld",&p);
                b+=p;
            }
            nim= nim^b;
        }
        printf("Case %lld: ",t);

        if(nim>0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
