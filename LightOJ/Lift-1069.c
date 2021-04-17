#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,a,b,sum,dif,i=1;

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%d %d",&a,&b);

        dif=abs(a-b);

        sum=(dif*4)+(a*4)+19;

        printf("Case %d: %d\n",i,sum);

        i++;
    }
    return 0;
}
