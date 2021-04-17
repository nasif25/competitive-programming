#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double n[1000005];

int main()
{
    long long t,i=1,j,num,base,digit;

    double sum,temp,mark;

    for(j=2;j<=1000000;j++)
        n[j]=n[j-1]+log10((double) j);


    scanf("%lld",&t);

    while(i<=t)
    {
        scanf("%lld %lld",&num,&base);

        if(num==0 || num==1)
        {
            printf("Case %lld: 1\n",i);
            i++;
            continue;
        }

        mark=log10((double)base);

        sum=n[num]/mark;

        temp=ceil(sum);

        if(temp==sum)
            temp+=1;

        digit=(long long)temp;

        printf("Case %lld: %lld\n",i,digit);

        i++;
    }
    return 0;
}
