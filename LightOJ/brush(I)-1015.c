#include <stdio.h>
int main()
{
    int t,i=1,sum,u,d[1005],j;
    char c;
    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%d",&u);
        sum=0;
        for(j=1;j<=u;j++)
        {
            scanf("%d",&d[j]);
                if(d[j]>0)
                    sum+=d[j];
        }
        printf("Case %d: %d\n",i,sum);
        i++;
    }
    return 0;
}
