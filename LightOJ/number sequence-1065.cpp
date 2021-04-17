#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
struct node
{
    ll x,y,z,w;
};
node multiply(node F,node M);
node power(node F, ll n);

ll fib(ll a, ll b, ll n)
{
    node F;
    F.x=1;
    F.y=1;
    F.z=1;
    F.w=0;
    F=power(F,n-1);

    return ((F.x%m*b%m)%m+(F.y%m*a%m)%m)%m;
}
node multiply(node F,node M)
{
    ll p,q,r,s;
    p=((F.x%m*M.x%m)%m+(F.y%m*M.z%m)%m)%m;
    q=((F.x%m*M.y%m)%m+(F.y%m*M.w%m)%m)%m;
    r=((F.z%m*M.x%m)%m+(F.w%m*M.z%m)%m)%m;
    s=((F.z%m*M.y%m)%m+(F.w%m*M.w%m)%m)%m;

    F.x=p;
    F.y=q;
    F.z=r;
    F.w=s;
    return F;
}
node power(node F, ll n)
{
    node M;
    M.x=M.y=M.z=1,M.w=0;

    if(n==1)
        return F;

    M=power(F,n/2);
    M=multiply(M,M);
    if(n%2==0)
        return M;
    else
        return multiply(F,M);
}
int main()
{
    ll t,a,b,n,ans,test,i;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);

        ll mod=1;

        for(i=1; i<=m; i++)
            mod*=10;
        m=mod;

        ans=0;
        if(n<2)
        {
            if(n==0)
                ans=a;
            else
                ans=b;
        }
        else
            ans=fib(a,b,n);

        printf("Case %lld: %lld\n", t, ans);
    }
    return 0;
}

