#include <bits/stdc++.h>
using namespace std;
#define LIMIT 5000000
bool flag[5000005];
unsigned long long phi[5000005];

void isprime()
{
    int i,j;

    for(i=3; i<=5000001; i++)
    {
        if(i%2==0)
        {
            flag[i]=1;
            phi[i]=i/2;
        }
        else
            phi[i]=i;
    }
    phi[2]=1;
    for(i=3;i<=5000001;i+=2)
    {
        if(flag[i]==1)
            continue;
        phi[i]-=1;

        for(j=i+i;j<=5000001;j+=i)
        {
            flag[j]=1;
            phi[j]=((phi[j]/i)*(i-1));
//            phi[j]*=(i-1);
//            phi[j]/=i;
        }
    }
    for(i=3;i<=5000000;i++)
    {
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}

int main()
{
    int test,i,j,a,b;
    unsigned long long sum;
    isprime();

    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        scanf("%d %d",&a,&b);
        sum=0;
        printf("Case %d: ",i);
        sum=phi[b]-phi[a-1];

        printf("%llu\n",sum);
    }
    return 0;
}
