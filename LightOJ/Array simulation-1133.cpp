#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,test,n,m,flag;
    long long a;
    char c;
    deque <long long> d;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&a);
            d.push_back(a);
        }
        flag=0;
        for(k=0;k<m;k++)
        {
            scanf(" %c",&c);
            if(c=='S')
            {
                scanf("%lld",&a);
                for(l=0;l<n;l++)
                    d[l]+=a;
            }
            else if(c=='M')
            {
                scanf("%lld",&a);
                for(l=0;l<n;l++)
                    d[l]*=a;
            }
            else if(c=='D')
            {
                scanf("%lld",&a);
                for(l=0;l<n;l++)
                    d[l]/=a;
            }
            else if(c=='P')
            {
                scanf("%d %d",&j,&l);
                if(flag%2!=0)
                {
                    j=n-j-1;
                    l=n-l-1;
                }
                swap(d[j],d[l]);
            }
            else if(c=='R')
                flag++;
        }
        cout<<"Case "<<i<<":\n";
        if(flag%2==0)
            {
                cout<<d[0];
                for(j=1;j<n;j++)
                    cout<<" "<<d[j];
            }
        else
        {
            cout<<d[n-1];
                for(j=n-2;j>=0;j--)
                    cout<<" "<<d[j];
        }
        cout<<endl;
        d.clear();
    }
    return 0;
}
