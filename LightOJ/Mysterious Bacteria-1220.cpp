#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,test;
    double s,p,j;
    ll sq,x,f,c,ans,i,k,z;

    scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld",&x);
        ans=0;
        k=1;
        if(x<0)
        {
            k=-1;
            x*=k;
        }
        sq=(ll)sqrt((double)x);
        sq*=k;
        x*=k;
        for(i=2*k; ; i+=k)
        {
            if(x%i==0)
            {
                z=x;
                //cout<<z<<" "<<i<<endl;
                while(z%i==0)
                {
                    z/=i;
                    ans++;
                    //cout<<z<<endl;
                    if(z==1)
                        break;
                }
                if(z==1)
                    break;
                else
                    ans=0;
            }
            if(i==sq)
                break;
        }
        if(ans==0)
            ans=1;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
