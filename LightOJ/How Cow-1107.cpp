#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1,x2,y1,y2,i=1,t,m,x,y,j;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&m);

        for(j=0;j<m;j++)
        {
            scanf("%d %d",&x,&y);

            if(j==0)
                printf("Case %d:\n",i);

            if(x>x1 && x<x2 && y>y1 && y<y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
        i++;
    }
    return 0;
}
