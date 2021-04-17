#include <bits/stdc++.h>
using namespace std;
int tree[300015];
void create(int n, int b, int e)
{
    if(b==e)
    {
        tree[n]=0;
        return;
    }
    int l,r,mid;
    l=n*2;
    r=l+1;
    mid=(b+e)/2;
    create(l,b,mid);
    create(r,mid+1,e);
    tree[n]=0;
}
void update(int n, int b, int e, int i, int j)
{
    if(j<b || e<i)
        return;
    if(i<=b && e<=j)
    {
        tree[n]++;
        return;
    }
    int l,r,mid;
    l=n*2;
    r=l+1;
    mid=(b+e)/2;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
}
int query(int n, int b, int e, int i,int j,int carry=0)
{
    if(j<b || e<i)
        return -1;
    if(i<=b && e<=j)
    {
        return tree[n]+carry;
    }
    int l,r,mid,left,right;
    l=n*2;
    r=l+1;
    mid=(b+e)/2;
    left=query(l,b,mid,i,j,tree[n]+carry);
    right=query(r,mid+1,e,i,j,tree[n]+carry);
    return max(left,right);
}
int main()
{
    int test,t,q,i,j,n,ans;
    string s;
    char c;
    scanf("%d",&test);
    getchar();
    for(t=1; t<=test; t++)
    {
        cin>>s;
        n=s.size();
        scanf("%d",&q);
        create(1,1,n);
        printf("Case %d:\n",t);
        while(q--)
        {
            getchar();
            scanf("%c",&c);

            if(c=='I')
            {
                scanf("%d %d",&i,&j);
                update(1,1,n,i,j);
            }
            else
            {
                scanf("%d",&i);
                ans=query(1,1,n,i,i);
                if(ans%2==0)
                    printf("%c\n",s[i-1]);
                else
                {
                    if(s[i-1]=='0')
                        printf("1\n");
                    else
                        printf("0\n");
                }
            }
        }
        s.clear();
    }
    return 0;
}
