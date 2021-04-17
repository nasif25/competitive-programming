#include <stdio.h>

unsigned long long fact(int x)
{
    if(x==0 || x==1)
        return 1;

    return x*fact(x-1);
}

int main()
{
    unsigned long long n,sum;
    int i,test,high,tell,j,count[50];

    scanf("%d",&test);

    for(i=1; i<=test; i++)
    {
        scanf("%lld",&n);

        if(n<3)
        {
            if(n==2)
                printf("Case %d: 0!+1!\n",i);
            if(n==1)
                printf("Case %d: 0!\n",i);
            continue;
        }

        for(j=0; j<=n; j++)
        {
            if(fact(j)>n)
            {
                high=j-1;
                break;
            }
        }

        if(fact(high)==n)
        {
            printf("Case %d: %d!\n",i,high);
            continue;
        }

        sum=0;
        for(j=high;j>=0;j--)
            {
                sum+=fact(j);

            if(sum<=n)
                count[j]=1;
            else
            {
                sum-=fact(j);
                count[j]=0;
            }
        }

        if(sum<n)
        {
            printf("Case %d: impossible\n",i);
            continue;
        }

        tell=1;
        for(j=0; j<=high; j++)
        {
            if(count[j]!=0)
            {
                if(tell==1)
                {
                    printf("Case %d: %d!",i,j);
                    tell++;
                }
                else
                    printf("+%d!",j);
            }
        }
        printf("\n");
    }
    return 0;
}
