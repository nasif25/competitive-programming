#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,test,n,i,j,ans,sq;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);

        sq=sqrt((double)n);
        ans=0;
        for(i=2;i<=sq;i++)
        {
            j=n/i;

            ans+=(j+i)*(j-i+1)/2;
            ans+=i*(j-i);
        }
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
