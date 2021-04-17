#include <bits/stdc++.h>
long long a[1000000],b[1000000];
int main()
{
    int test,i;
    long long x,p,q,r,j,sq,m,n,tem;

    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%lld %lld",&p,&q);
        r=p-q;
        sq=1+(long long)sqrt((double)r);
        if(r<=q)
            printf("Case %d: impossible",i);
        else
        {
            m=n=0;
            for(j=1;j<sq;j++)
            {
                if(r%j==0)
                {
                    if(j>q)
                        a[m++]=j;
                    tem=r/j;
                    if(tem>q && tem>j)
                        b[n++]=tem;
                }
            }
            printf("Case %d:",i);
            for(j=0;j<m;j++)
                printf(" %lld",a[j]);
            for(j=n-1;j>=0;j--)
                printf(" %lld",b[j]);
        }
        printf("\n");
    }
    return 0;
}
