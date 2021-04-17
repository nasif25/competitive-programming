#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,t,i,l;
    long long b,z;
    char a[205];
    bool flag;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf(" %s %lld",a,&b);

        if(a[0]=='-')
            i=1;
        else
            i=0;

        if(a[i]=='0')
            flag=1;
        else
            flag=0;

        if(flag==0)
        {
            l=strlen(a);
            z=0;
            for(; i<l; i++)
            {
                z=z*10+a[i]-'0';
                z=z%b;
            }
            if(z==0)
                flag=1;
        }

        if(flag==1)
            printf("Case %d: divisible\n",t);
        else
            printf("Case %d: not divisible\n",t);
    }
    return 0;
}
