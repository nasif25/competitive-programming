#include <bits/stdc++.h>
using namespace std;
struct node
{
    int mx,mn;
};
node a[200005];
node tree[600015];

void create(int n, int b, int e)
{
    int left,right,mid,l,r;
    if(b==e)
    {
        tree[n]=a[b];
        return;
    }
    left=n*2;
    right=left+1;
    mid=(b+e)/2;

    create(left,b,mid);
    create(right,mid+1,e);
    tree[n].mx=max(tree[left].mx,tree[right].mx);
    tree[n].mn=min(tree[left].mn,tree[right].mn);

    return;
}
node query(int n, int b, int e, int i, int j)
{
    node g,l,r;
    g.mx=0,g.mn=1000000000;
    int left,right,mid;

    if(j<b||e<i)
        return g;
    if(i<=b && e<=j)
        return tree[n];
    mid=(b+e)/2;
    left=n*2;
    right=left+1;
    l=query(left,b,mid,i,j);
    r=query(right,mid+1,e,i,j);

    g.mx=max(l.mx,r.mx);
    g.mn=min(l.mn,r.mn);

    return g;
}

int main()
{
    int test,t,n,d,p,q,ans,dif;
    node temp;

    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d %d",&n,&d);
        ans=0;
        for(p=1; p<=n; p++)
        {
            scanf("%d",&q);
            a[p].mx=a[p].mn=q;
        }

        create(1,1,n);
        q=n-d+1;

        for(p=1; p<=q; p++)
        {
            temp=query(1,1,n,p,p+d-1);
            dif=temp.mx-temp.mn;
            if(dif>ans)
                ans=dif;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
