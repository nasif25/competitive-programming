#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,t,n,x,y,z,v,l;
    string a,b;
    map<int,string> mp;
    map<int,string>::iterator it;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        while(n--)
        {
            getchar();
            cin>>a>>x>>y>>z;
            v=x*y*z;
            mp[v]=a;
        }
        l=mp.size();
        if(l==1)
            printf("Case %d: no thief\n",t);
        else
        {
            it=mp.begin();
            a=it->second;
            it=mp.end();
            it--;
            b=it->second;
            cout<<"Case "<<t<<": "<<b<<" took chocolate from "<<a<<endl;
        }
        mp.clear();
    }
    return 0;
}
