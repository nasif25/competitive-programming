#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ps push
#define INF 1000000000
struct node
{
    ll num, ln;
} a[100005];

stack<ll> stk;
map<ll, vector<ll> > mp;
ll vis[100005],save[100005],mark;
bool check[100005],fin[100005];

bool comp(node x, node y)
{
    if(x.num< y.num)
        return true;
    else if( x.num== y.num && x.ln<y.ln)
        return true;
    else return false;
}
ll dfs(ll src)
{
    ll i, in, l=-1, v, z;
    vis[src]=1;
    check[src]=1;
    stk.ps(src);

    while(!stk.empty())
    {
        v=stk.top();
        if(vis[v]>l)
        {
            in=v;
            l=vis[v];
        }
        stk.pop();
        z=mp[v].size();

        for(i=0; i<z; i++)
        {
            if(check[mp[v][i]]==0)
            {
                check[mp[v][i]]=1;
                vis[mp[v][i]]=vis[v]+1;
                stk.ps(mp[v][i]);
            }
        }
    }

    return in;
}
ll dfs2(ll src)
{
    ll i, in, l=-1, v, z;
    vis[src]=1;
    fin[src]=1;
    mark=1;
    stk.ps(src);

    while(!stk.empty())
    {
        v=stk.top();
        if(vis[v]>l)
        {
            in=v;
            l=vis[v];
        }
        stk.pop();
        z=mp[v].size();

        for(i=0; i<z; i++)
        {
            if(fin[mp[v][i]]==0)
            {
                mark++;
                fin[mp[v][i]]=1;
                vis[mp[v][i]]=vis[v]+1;
                stk.ps(mp[v][i]);
            }
        }
    }
    return l;
}
int main()
{
//    freopen("out.txt","w",stdout);
    ll t, test, n, m, i, in, l, u, v, q, k, j, ans, x, mid, gaba;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld", &n, &m);

        for(i=0; i<m; i++)
        {
            scanf("%lld %lld",&u,&v);
            mp[u].pb(v);
            mp[v].pb(u);
        }

        memset(check,0,sizeof(check));
        memset(fin,0,sizeof(fin));
        j=0;
        for(i=1; i<=n; i++)
        {
            if(check[i]==0)
            {
                in=dfs(i);
                l=dfs2(in);
                a[j].ln=l;
                a[j++].num=mark;
                //cout<<i<<" "<<j-1<<" b "<<a[j-1].ln<<" "<<a[j-1].num<<endl;
            }
        }
        sort(a,a+j,comp);

        save[j-1] = a[j-1].ln;
        for(i=j-2; i>=0; i--)
        {
            save[i]= max(a[i].ln, save[i+1]);
        }

        scanf("%lld",&q);
        printf("Case %lld:\n",t);

        while(q--)
        {
            ans=INF;
            scanf("%lld",&k);

            i=0;
            x=j-1;
            gaba=-1;
            while(i<=x)
            {
                mid=(i+x)/2;
                //cout<<i<<" "<<x<<" "<<mid<<" "<<a[mid].num<<" a "<<k<<endl;
                if(a[mid].num<k)
                {
                    i=mid+1;
                }
                else
                {
                    gaba = mid;
                    x = mid - 1;
                }
            }

            //cout<<mid<<" "<<a[mid].num<<" "<<save[mid] <<" j "<<n<<endl;

            mid = gaba;

            if(mid != -1)
            {
                if(k<=save[mid])
                    ans=min(ans,k-1);
                else
                    ans=min(ans,save[mid]-1+(k-save[mid])*2);
            }

            if(mid == -1)
                printf("impossible\n");
            else
                printf("%lld\n",ans);
        }
        mp.clear();
    }
    return 0;
}

