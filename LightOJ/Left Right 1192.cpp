#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t,test,k,i,mark,v,p;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&k);
        mark=0;

        for(i=0;i<k;i++)
        {
            scanf("%lld %lld",&v,&p);

            mark=mark^(p-v-1);
        }

        printf("Case %lld: ",t);
        if(mark>0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
