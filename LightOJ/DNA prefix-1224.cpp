#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
ll hi;
struct node
{
    node *a[5];
    ll r;
    node()
    {
        for(int i=0; i<5; i++)
            a[i]=NULL;
        r=0;
    }
}*root;
void ins(char *st)
{
    node *x=root;
    ll id,j,len,m;
    len=strlen(st);
    for(j=0; j<len; j++)
    {
        id=st[j]-'A';
        if(id==2)
            id--;
        else if(id==6)
            id=2;
        else if(id!=0)
            id=3;
        if(x->a[id]==NULL)
            {
                x->a[id]=new node();
                //cout<<"m "<<id<<endl;
            }

        x=x->a[id];
        //cout<<"id "<<id<<" "<<x->r<<endl;
        x->r++;
        m=x->r*(j+1);


        //cout<<x->r<<" "<<j+1<<" "<<m<<endl;
        if(m>hi)
            hi=m;

    }
}
void del(node *n)
{
    ll i;
    for(i=0;i<5;i++)
        {
            if(n->a[i])
                del(n->a[i]);
        }
        delete(n);
}

int main()
{
    ll t,test,x,i,q;
    char s[1000];



    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        root=new node();
        hi=0;
        scanf("%lld",&q);
        while(q--)
        {
            scanf("%s",s);
            ins(s);
        }
        printf("Case %lld: %lld\n",t,hi);
        del(root);
    }
    return 0;
}
