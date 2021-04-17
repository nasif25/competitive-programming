#include <bits/stdc++.h>
int main()
{
    int t,test,ax,ay,bx,by,cx,cy,dx,dy,area;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);

        dx=cx-(bx-ax);
        dy=ay+(cy-by);

        area=abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
        printf("Case %d: %d %d %d\n",t,dx,dy,area);
    }
    return 0;
}
