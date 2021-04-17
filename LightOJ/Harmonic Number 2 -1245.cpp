#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll i,t,c,test,n,ans,sq,x,p,q;

    scanf("%lld",&test);
    for(c=1; c<=test; c++)
    {
        ans=0;
        scanf("%lld",&n);
        t=q=n;
        for(i=1;; i++)
        {
            x=n/i;
            p=(t-x)*(i-1);
            //cout<<ans<<" "<<i<<" "<<t<<" "<<x<<" "<<p<<" "<<q<<endl;
            if(x==q && x!=0)
            {
                if(n/x>i)
                    i=n/x;
                continue;
            }
            ans+=p;
            if(x<=0)
                break;
            t=x;
            q=x;
        }
        printf("Case %lld: %lld\n",c,ans);
    }
    return 0;
}
