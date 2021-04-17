#include <bits/stdc++.h>
using namespace std;
int prime[105];
int num[30][105];
bool flag[105];

void isprime()
{
    int i,j,k=0,x,sq=int(sqrt(100.0))+1;

    for(i=2; i<=sq; i+=2)
    {
        if(flag[i]==0)
        {
            x=i;
            for(j=i*i; j<=101; j=i*x)
            {
                flag[j]=1;
                x++;
            }

            if(i==2)
                i--;
        }
    }
    prime[0]=2;
    for(i=3,k=1; i<=101; i+=2)
    {
        if(flag[i]==0)
            prime[k++]=i;

    }
}
void isdiv()
{
    int i,j,k,sq,x,t,temp;
    num[0][2]=1;

    for(i=3;i<=100;i++)
    {
        sq=(int)sqrt((double)i)+1;
        x=i,t=0;
        for(j=0;prime[j]<=sq;j++)
        {
            temp=0;
            while(x%prime[j]==0)
            {
                temp++;
                x/=prime[j];
            }
             num[t++][i]=temp;
        }
        if(x!=1)
            {
                for(t=t;;t++)
                {
                    if(prime[t]==x)
                    {
                        num[t][i]=1;
                        break;
                    }
                }
            }
    }
}
int main()
{
    isprime();
    isdiv();
    int t,test,n,i,j,sum,mark;
    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        printf("Case %d: %d =",t,n);
        mark=0;
        for(i=0;i<=25;i++)
        {
            sum=0;
            for(j=2;j<=n;j++)
            {
                if(num[i][j]!=0)
                    sum+=num[i][j];
            }
            if(sum!=0)
            {
                if(mark!=0)
                    printf(" *");

                printf(" %d (%d)",prime[i],sum);
                mark=1;
            }
        }
        printf("\n");
    }

    return 0;
}
