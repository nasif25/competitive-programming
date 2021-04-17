#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ar[17][17],dp[17][65536],n, limit;

ll call(ll pos, ll mask)
{
    if(pos==n || mask==limit)
        return 0;

    if(dp[pos][mask]!=-1)
        return dp[pos][mask];

    ll i, j, hi=0, p1;
    //ll p1=call(pos+1,mask),p2=0;

    for(i=pos; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            //cout<<mask<<" "<<(1<<j)<<" "<<(mask & (1<<j))<<endl;
            if((mask & (1<<j))==0)
            {
                //cout<<"a "<<pos<<" "<<mask<<" "<<j<<" "<<hi<<" "<<(mask | (1<<j))<<endl;

                p1=call(pos+1,(mask | (1<<j)))+ar[pos][j];
                hi=max(hi,p1);

                //cout<<"b "<<x<<" "<<j<< " "<<s<<" "<<hi<<endl;
            }
        }
    }
    return dp[pos][mask]=hi;
}

int main()
{
    ll t,i,j,test,ans;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld",&n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%lld",&ar[i][j]);
        }

        for(i=0; i<n; i++)
        {
            //take[i]=0;
            for(j=0; j<n; j++)
                dp[i][j]=-1;
        }
        ll mask=0;

        limit=1;
        for(i=1; i<=n; i++)
            limit*=2;

        limit--;
//        cout<<"limit "<<limit<<endl;
        memset(dp,-1,sizeof(dp));

        ans=call(0, mask);

        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

