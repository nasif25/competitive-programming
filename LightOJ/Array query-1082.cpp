#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a[100005],tree[300005];

void create(int n, int b, int e)
{
    int left,right,mid;
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
    tree[n]=min(tree[left],tree[right]);
    return;
}

int query(int n, int b, int e, int i, int j)
{
    int left,right,mid,l,r;
    if(j<b || e<i)
        return 10000000;
    if(i<=b && e<=j)
        return tree[n];

    left=n*2;
    right=left+1;
    mid=(b+e)/2;
    l=query(left,b,mid,i,j);
    r=query(right,mid+1,e,i,j);
    return (min(l,r));
}

int main()
{
    int t,test,i,j,p,q,n;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        create(1,1,n);

        for(p=1;p<=q;p++)
        {
            scanf("%d %d",&i,&j);
            if(p==1)
                printf("Case %d:\n",t);

            printf("%d\n",query(1,1,n,i,j));
        }
    }
    return 0;
}
