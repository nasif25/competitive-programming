#include <bits/stdc++.h>
using namespace std;

int k;
set<string> s;
set<string>::iterator it;
void perm(string a, int i,int n)
{
    int j=65+n,l;
    char p='A';
    bool f=0;
    map<char,int> mp;
    if(k==0)
    {
        return;
    }

    for(l=0; l<i && p<j; l++)
    {
        if(p==a[l])
        {
            p++;
            l--;
        }
    }
    if(i==n)
    {
        //a+='\0';
        for(p='A'; p<j; p++)
        {
            for(l=0; l<n; l++)
            {
                if(a[l]==p)
                {
                    mp[p]++;
                    if(mp[p]>1)
                        f=1;
                }
            }
        }
        if(f==0)
        {
            s.insert(a);
            k--;
        }
        return;
    }
    if(l==i)
    {
        a+=p;
        for(; p<j; p++)
        {
                a[l]=p;
                perm(a,i+1,n);
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,c,n,i;

    scanf("%d",&t);
    string a;
    for(c=1; c<=t; c++)
    {
        scanf("%d %d",&n,&k);
        a="";
        printf("Case %d:\n",c);

        perm(a,0,n);
//        cout<<s.size()<<endl;
        for(it=s.begin(); it!=s.end(); it++)
            cout<<*it<<"\n";

        s.clear();
    }
    return 0;
}
