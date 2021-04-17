#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 100000000000
ll prime[1001],vis[1010];
bool stat[1101];
deque<ll> q;

void isprime()
{
    ll i,j,k=0,sq=sqrt(1050);

    stat[0]=stat[1]=1;
    prime[k++]=2;
    for(i=4; i<=1050; i+=2)
        stat[i]=1;

    for(i=3; i<=1050; i+=2)
    {
        if(stat[i]==0)
        {
            prime[k++]=i;

            if(i<=sq)
            {
                for(j=i*i; j<=1050; j+=i+i)
                    stat[j]=1;
            }
        }
    }
}

ll bfs(ll s, ll t)
{
    ll v, i, k, x, n, ans=inf;
    bool c;
    vis[s]=0;
    q.push_back(s);

    while(!q.empty())
    {
        n=q.front();
        q.pop_front();

        v=n;
        k=0;
        while(v>1 && v<t)
        {
            c=0;
            while(v%prime[k]==0)
            {
                v/=prime[k];
                c=1;
            }
//            if(n==917)
//                    cout<<v<<" t "<<prime[k]<<endl;
            if(c==1)
            {
                x=n+prime[k];

                if(x==t)
                {
                    ans=min(ans,vis[n]+1);
//                    cout<<n<<" "<<x<<" "<<prime[k]<<endl;
                }

                if(x<t && stat[x]==1 && vis[x]==-1)
                {
//                    cout<<x<<" "<<vis[n]+1<<endl;
                    vis[x]=vis[n]+1;
                    q.push_back(x);
                }
            }
            k++;
        }
    }
    return ans;
}

int main()
{
    ll i, s, t, test, T, d, v, ans, k;

    isprime();

    scanf("%lld",&test);

    for(T=1; T<=test; T++)
    {
        ans=inf;
        scanf("%lld %lld",&s,&t);

        if(s==t)
        {
            printf("Case %lld: 0\n",T);
            continue;
        }
        else if(s==1 || stat[s]==0)
        {
            printf("Case %lld: -1\n",T);
            continue;
        }
        else
        {
            memset(vis,-1,sizeof(vis));
            ans=bfs(s,t);
            if(ans<inf)
                printf("Case %lld: %lld\n",T,ans);
            else
                printf("Case %lld: -1\n",T);
        }
    }
    return 0;
}
