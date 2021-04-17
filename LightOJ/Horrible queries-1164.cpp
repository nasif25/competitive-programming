#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll sum,prop;
} tree[300005];
void create(ll n, ll b, ll e)
{
    if(b==e)
    {
        tree[n].sum=tree[n].prop=0;
        return;
    }
    ll l,r,mid;
    l=n*2;
    r=l+1;
    mid=(b+e)/2;
    create(l,b,mid);
    create(r,mid+1,e);
    tree[n].sum=tree[n].prop=0;
}

void update(ll n, ll b, ll e, ll i, ll j,ll x)
{
    if(j<b || e<i)
        return;
    if(i<=b && e<=j)
    {
        tree[n].sum+=((e-b)+1)*x;
        tree[n].prop+=x;
        //cout<<b<<" "<<e<<" "<<n<<" "<<x<<endl;
        return;
    }
    ll l,r,mid;
    l=n*2;
    r=l+1;
    mid=(b+e)/2;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);
    tree[n].sum=tree[l].sum+tree[r].sum+((e-b)+1)*tree[n].prop;
}
ll query(ll n, ll b, ll e, ll i, ll j, ll carry=0)
{
    if(j<b || e<i)
        return 0;
    if(i<=b && e<=j)
        return tree[n].sum+((e-b)+1)*carry;
    ll l,r,mid,left,right;
    l=n*2;
    r=l+1;
    mid=(b+e)/2;
    left=query(l,b,mid,i,j,carry+tree[n].prop);
    right=query(r,mid+1,e,i,j,carry+tree[n].prop);

    return left+right;
}
int main()
{
    ll t, test, n, c, i, j, x, q;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&c);
        create(1,1,n);
        printf("Case %lld:\n", t);
        while(c--)
        {
            scanf("%lld",&q);
            if(q==0)
            {
                scanf("%lld %lld %lld",&i,&j,&x);
                update(1,1,n,i+1,j+1,x);
            }
            else
            {
                scanf("%lld %lld",&i,&j);
                printf("%lld\n",query(1,1,n,i+1,j+1));
            }
        }
    }
    return 0;
}
