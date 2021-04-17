#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long fact[1000100];

void findfact()
{
    long long x,i;
    fact[0]=1;
    fact[1]=1;
    for(i=2; i<=1000000; i++)
        fact[i]=((i%1000003)*(fact[i-1]%1000003))%1000003;
}

long long mod(long long b,long long p,long long m)
{
    long long d;
    if(p==0)
        return 1;
    if(p%2==0)
    {
        d=mod(b,p/2,m)%m;
        //cout<<"b= "<<b<<"p= "<<p<<"m= "<<m<<endl;
        return (d*d)%m;
    }
    else
    {
        p--;
        d=mod(b,p/2,m)%m;
        //cout<<"b= "<<b<<" p= "<<p<<" m= "<<m<<endl;
        return ((b%m)*d*d)%m;
    }
}

int main()
{
    long long n,k,test,t,ans,i,j,temp1,temp2;
    findfact();
    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&k);
        //cout<<fact[n]<<endl;
        temp1=mod(fact[k],1000003-2,1000003);
        temp2=mod(fact[n-k],1000003-2,1000003);
        ans=((fact[n]%1000003)*temp1*temp2)%1000003;

        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
