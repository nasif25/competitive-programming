#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;
int main()
{
    //freopen("out.txt","w",stdout);
    llu t,test,i,x,ans;

    scanf("%llu",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%llu",&x);

        ans=x+x/9;

        printf("Case %llu:",t);

        if(ans%10==0)
            printf(" %llu",ans-1);
        printf(" %llu\n",ans);
    }

    return 0;
}
