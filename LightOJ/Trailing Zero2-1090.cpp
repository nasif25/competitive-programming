#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long test,t,n,r,p,q,i,up,c,d,m,a5,a2,b5,b2,c5,c2;

    scanf("%lld",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);

        m=n;
        c=0;
        while(m/5>0)
        {
            m/=5;
            c+=m;
        }
        a5=c;
        m=n;
        d=0;
        while(m/2>0)
        {
            m/=2;
            d+=m;
        }
        a2=d;
        //cout<<"1 "<<a5<<" "<<a2<<endl;
        m=n-r;
        c=0;
        while(m/5>0)
        {
            m/=5;
            c+=m ;
        }
        b5=c;
        m=n-r;
        d=0;
        while(m/2>0)
        {
            m/=2;
            d+=m;
        }
        b2=d;

        a5-=b5;
        a2-=b2;
        //cout<<"2 "<<a5<<" "<<a2<<endl;
        m=r;
        c=0;
        while(m/5>0)
        {
            m/=5;
            c+=m;
        }
        c5=c;
        m=r;
        d=0;
        while(m/2>0)
        {
            m/=2;
            d+=m;
        }
        c2=d;
        a5-=c5;
        a2-=c2;
        //cout<<a5<<" "<<a2<<endl;
        m=p;
        c=0;
        while(m%5==0)
        {
            m/=5;
            c++;
        }
        m=p;
        d=0;
        while(m%2==0)
        {
            m/=2;
            d++;
        }
        c*=q;
        d*=q;
        a5+=c;
        a2+=d;

        if(a5<=a2)
            up=a5;
        else
            up=a2;

        printf("Case %lld: %lld\n",t,up);
    }
    return 0;
}
