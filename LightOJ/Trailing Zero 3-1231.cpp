#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll binary(ll b,ll e)
{
    int mid,sum,x;
    mid=(b+e)/2;
    sum=mid;
    x=mid;
    while(x/5!=0)
    {
        x/=5;
        sum+=x;
    }
    if(sum==n)
        return mid;
    if(sum<n)
        b=mid+1;
    else
        e=mid-1;
    if(e<b)
        return -1;
    return binary(b,e);
}
int main()
{
    int test,t,b,e,mid,l,x,sum;

    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%lld",&n);
        x=n;
        sum=x;
        while(x/5!=0)
        {
            x/=5;
            sum+=x;
        }
        if(sum>n)
            x=binary(1,n);
        if(x>=0)
            printf("Case %d: %lld\n",t,x*5);
        else
            printf("Case %d: impossible\n",t);

    }
    return 0;
}
