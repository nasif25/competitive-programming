#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,t,r1,r2,c1,c2,dx,dy,temp,flag;
    //bool flag;
    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        flag=0;
        dx=abs(r1-r2);
        dy=abs(c1-c2);

        if((dx%2==0 && dy%2==0)||(dx==0 && dy%2==0)||(dy==0 && dx%2==0)||(abs(dx-dy)%2)==0)
        {
            if(dx==dy)
                flag=1;
            else
                flag=2;
        }
        printf("Case %d: ",t);
        if(flag==0)
            printf("impossible\n");
        else if(flag==1)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
