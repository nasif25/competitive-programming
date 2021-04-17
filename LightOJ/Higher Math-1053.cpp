#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,i=1,t;
    long long maxm,sum;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%d %d %d",&a,&b,&c);

        if(a>=b && a>=c)
        {
            maxm=a*a;
            sum=b*b+c*c;
        }
        else if(b>=a && b>=c)
        {
            maxm=b*b;
            sum=a*a+c*c;
        }
        else
        {
            maxm=c*c;
            sum=a*a+b*b;
        }

        if(maxm==sum)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);

        i++;
    }
    return 0;
}
