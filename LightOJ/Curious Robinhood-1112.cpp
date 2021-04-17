#include <bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx*3];

void in(int node, int b, int e)
{
    int left,right,mid;
    if(b==e)
    {
        tree[node]=arr[b];
//        cout<<"b= "<<b<<" e= "<<e<<" node= "<<node<<" tree[node]= "<<tree[node]<<" arr[b]= "<<arr[b]<<endl;
        return;
    }
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    in(left,b,mid);
    in(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
//    cout<<"left= "<<left<<" tree[left]= "<<tree[left]<<" right= "<<right<<" tree[right]= "<<tree[right]<<" node= "<<node<<" tree[node]= "<<tree[node]<<" arr[b]= "<<arr[b]<<endl;
}
int query(int node, int b, int e, int i, int j)
{
    int left,right,mid,p1,p2;
    if(i>e||j<b)
        {
             //cout<<"b= "<<b<<" e= "<<e<<endl;
            return 0;
        }
    if(b>=i && e<=j)
        {
//             cout<<"b= "<<b<<" e= "<<e<<" node= "<<node<<" tree[node]= "<<tree[node]<<endl;
            return tree[node];
        }
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
//    cout<<"b= "<<b<<" e= "<<e<<" p1= "<<p1<<" p2= "<<p2<<endl;
    return p1+p2;
}
void update(int node, int b, int e, int i, int v)
{
    int left,right,mid;
    if(i>e||i<b)
        return;
    if(b==e)
    {
        tree[node]+=v;
        return;
    }
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    update(left,b,mid,i,v);
    update(right,mid+1,e,i,v);
    tree[node]=tree[left]+tree[right];
//    cout<<"b= "<<b<<" e= "<<e<<endl;
//    cout<<"left= "<<left<<" tree[left]= "<<tree[left]<<" right= "<<right<<" tree[right]= "<<tree[right]<<" node= "<<node<<" tree[node]= "<<tree[node]<<endl;

}
int main()
{
    int t,test,q,n,y,z,i,j,v,sum;

    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&q);

        for(y=1;y<=n;y++)
            scanf("%d",&arr[y]);
        in(1,1,n);
        for(y=0;y<q;y++)
        {
            scanf("%d",&z);
            if(y==0)
                printf("Case %d:\n",t);
            if(z==1)
            {
                scanf("%d",&i);
                printf("%d\n",arr[i+1]);
                update(1,1,n,i+1,-1*arr[i+1]);
                arr[i+1]=0;
            }
            else if(z==2)
            {
                scanf("%d %d",&i,&v);
                arr[i+1]+=v;
                update(1,1,n,i+1,v);
            }
            else
            {
                scanf("%d %d",&i,&j);
                sum=query(1,1,n,i+1,j+1);
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
