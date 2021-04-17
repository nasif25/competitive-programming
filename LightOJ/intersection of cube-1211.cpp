#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,test,n,x1,y1,z1,x2,y2,z2,max1,max2,max3,min1,min2,min3,dif1,dif2,dif3,ans;

    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        ans=max1=max2=max3=0;
        min1=min2=min3=1001;
        while(n--)
        {
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            if(x1>max1)
                max1=x1;
            if(y1>max2)
                max2=y1;
            if(z1>max3)
                max3=z1;
            if(x2<min1)
                min1=x2;
            if(y2<min2)
                min2=y2;
            if(z2<min3)
                min3=z2;
        }
        dif1=min1-max1;
        dif2=min2-max2;
        dif3=min3-max3;

        if(dif1>0 || dif2>0 || dif3>0)
        {
            ans=1;
            if(dif1>0)
                ans*=dif1;
            if(dif2>0)
                ans*=dif2;
            if(dif3>0)
                ans*=dif3;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
