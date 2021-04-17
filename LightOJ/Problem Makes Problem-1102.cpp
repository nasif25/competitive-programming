#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007
ll fact[2000005];
ll mod(ll b, ll p)
{
    ll d;
    if(p==0)
        return 1;
    d=mod(b,p/2);
    d=(d%m*d%m)%m;
    if(p%2==0)
        return d;
    else
        return (b%m*d%m)%m;
}
int main()
{
    ll test,t,n,i,k,ans,x,y;

    scanf("%lld",&test);
    fact[0]=1;
    for(i=1;i<=2000001;i++)
        {
            fact[i]=(fact[i-1]%m*i%m)%m;
            //cout<<fact[i]<<endl;
        }
    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&k);
        //k--;
        x=fact[n+k-1];
//        cout<<x<<endl;
        y=(fact[k-1]%m*fact[n]%m)%m;
//        cout<<y<<endl;
        y=mod(y,m-2);
//        cout<<y<<endl;
        ans=(x%m*y%m)%m;
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
