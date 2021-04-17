#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t,test,o,i,j;

    char a[]="Alice",b[]="Bob",c[10];

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %s",&o,c);

        if(o%3==0)
        {
            printf("Case %lld: %s\n", t, a);
        }
        else if(o%3==1)
        {
            printf("Case %lld: %s\n", t, b);
        }
        else
        {
            if(!strcmp(a,c))
            {
                printf("Case %lld: %s\n", t, a);
            }
            else
            {
                printf("Case %lld: %s\n", t, b);
            }
        }
    }
    return 0;
}
