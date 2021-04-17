#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i=1;

    unsigned long long num,s,j,mark,x,y;

    double temp;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%lld",&num);

        temp=sqrt((double)num);

        j=(unsigned long long)ceil(temp);
        s=j*j;
        mark=s-j+1;

        if(num==mark)
        {
            printf("Case %d: %lld %lld\n",i,j,j);
            i++;
            continue;
        }

        if(j%2==0)
        {
            if(num>mark)
            {
                x=j;
                y=s-num+1;
            }
            else
            {
                x=num+j-mark;
                y=j;
            }
        }
        else
        {
            if(num>mark)
            {
                x=s-num+1;
                y=j;
            }
            else
            {
                x=j;
                y=num+j-mark;
            }
        }
        printf("Case %d: %lld %lld\n",i,x,y);
        i++;
    }
    return 0;
}
