#include <stdio.h>
int main()
{
    int t,i=1,j,a[3],b,x[3],y;

    scanf("%d",&t);

    while(i<=t)
    {
        for(j=0; j<2; j++)
        {
            scanf("%d",&a[j]);

            if(a[j]%3==0)
            {
                x[j]=(a[j]/3)*2;
            }
            else if(a[j]%3==1)
            {
                if(a[j]/3==0)
                    x[j]=0;
                else
                    x[j]=(a[j]/3)*2;
            }
            else if(a[j]%3==2)
            {
                if(a[j]/3==0)
                    x[j]=1;
                else
                    x[j]=(a[j]/3)*2+1;
            }
        }
        y=x[1]-x[0];

        if(a[0]%3!=1)
            y++;

        printf("Case %d: %d\n",i,y);
        i++;
    }
    return 0;
}
