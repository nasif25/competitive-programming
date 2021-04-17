#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll test,t,n,m,i,j,p,b,nim;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);

        nim=b=0;
        for(i=1;i<=n;i++)
        {
                scanf("%lld",&p);
                b+=p;
                nim = nim^p;
        }


        printf("Case %lld: ",t);

        if(b==n && n%2==0)
            printf("Alice\n");
        else if(b==n && n%2==1)
            printf("Bob\n");
        else if(nim>0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
