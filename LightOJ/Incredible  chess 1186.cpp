#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t, test, n, w[101],b[101], d, i;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&w[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&b[i]);

        d=0;

        for(i=0;i<n;i++)
            d=d^(max(w[i],b[i])-min(w[i],b[i])-1);

        printf("Case %lld: ",t);

        if(d>0)
            printf("white wins\n");
        else
            printf("black wins\n");
    }
    return 0;
}
