#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t,test,n,s1,s2,sum,i,sq,x;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);
        sq=(ll)sqrt((double)n);
        s1=s2=0;
        for(i=2;i<=sq;i++)
        {
            x=n/i;
            s1+=(x*(x+1)/2-i*(i-1)/2);
            s2+=(x-i)*i;
        }
        sum=s1+s2;
        printf("Case %lld: %lld\n",t,sum);
    }
    return 0;
}
