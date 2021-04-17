#include <bits/stdc++.h>

int main()
{
    int test,t,one,mark;

    long long x;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&x);

        one=0;

        while(1)
        {
            mark=x%2;

            if(mark==1)
                one++;

            x/=2;

            if(x==0)
                break;
        }
        if(one%2==0)
            printf("Case %d: even\n",t);
        else
            printf("Case %d: odd\n",t);
    }
    return 0;
}
