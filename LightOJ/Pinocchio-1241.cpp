#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test,t,n,i,num,x,y;
    scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        y=2;
        num=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            if(x>y)
                num+=(int)ceil(((double)x-y)/5);
            y=x;
        }
        printf("Case %d: %d\n",t,num);
    }
    return 0;
}
