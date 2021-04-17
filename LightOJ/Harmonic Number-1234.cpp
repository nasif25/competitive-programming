#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,t=1,test,n;
    double a[200005],x=0;
    a[0]=0;

    for(i=1; i<=100000000; i++)
    {
        x+=(1/(double)i);
        if(i%500==0)
            a[t++]=x;
    }

    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        i=n/500;
        x=a[i];

        for(i=(i*500)+1; i<=n; i++)
            x+=1/(double)i;

        printf("Case %d: %.12g\n",t,x);
    }
    return 0;
}
