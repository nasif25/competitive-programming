#include <bits/stdc++.h>
using namespace std;
#define M 65600
#define sq 257
#define m 1000000007
#define ll long long
ll prime[65600];
bool stat[65600];
void isprime()
{
    int i,j,k=1,p;
    prime[0]=2;
    for(i=3; i<=M; i+=2)
    {
        if(stat[i]==1)
            continue;
        prime[k++]=i;
        if(prime[k-1]<=sq)
        {
            p=2*i;
            for(j=i*i; j<=M; j+=p)
                stat[j]=1;
        }
    }
}

ll mod(ll b, ll p,ll mo)
{
    ll d;
    if(p<=0)
        return 1;
    if(p%2==0)
    {
        d= mod(b,p/2,mo)%mo;
        //cout<<"D "<<d<<" p "<<p<<endl;
        return ((d%mo*d%mo)%mo);
    }
    else
    {
        d= mod(b,p/2,mo)%mo;
        //cout<<"D "<<d<<" p "<<p<<endl;
        return ((b%mo*(d%mo*d%mo)%mo)%mo);
    }
}
int main()
{
    int t,test,i,s;
    ll x,y,sum,p,mark,a,b,z;
    isprime();
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&x,&y);
        sum=1;
        s=sqrt(x);
        for(i=0; prime[i]<=s; i++)
        {
            mark=0;
            if(x%prime[i]==0)
            {
                while(x%prime[i]==0)
                {
                    x/=prime[i];
                    mark++;
                }
            }
            if(mark>0)
            {
                mark*=y;
                mark++;
                //      cout<<"1 "<<prime[i]<<" "<<mark<<endl;
                // cout<<"2 "<<mark<<endl;
                a=(mod(prime[i],mark,m)-1+m)%m;
                //   cout<<"a "<<a<<endl;
                b=mod(((prime[i]%m-1+m)%m),m-2,m)%m;
                // cout<<"b "<<b<<endl;
                z=(a%m*b%m)%m;
                sum=(sum%m*z%m)%m;
            }
            //cout<<"3 "<<sum<<endl;
        }
        if(x!=1)
        {
            a=(mod(x,y + 1,m)-1+m)%m;
            //cout<<"a1 "<<a<<endl;
            b=mod((x%m-1+m)%m,m-2,m)%m;
            // cout<<"b1 "<<b<<endl;
            z=(a%m*b%m)%m;
            sum=(sum%m*z%m)%m;
        }

        printf("Case %d: %lld\n",t,sum);
    }
    return 0;
}
