#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define uu first
#define vv second
#define inf 100000000
map <int, vector<int> > mp;
//priority_queue <pii,vector<pii>, greater<pii> > pq;
int n, busy[201], lvl[201];
void dij(int src)
{
    int i,j,z,c,v,k,l,mark=0;
    bool f;
    pii u;
    for(i=0; i<=n; i++)
        lvl[i]=inf;
    lvl[src]=0;

    for(i=1; i<n; i++)
    {
        f=false;
        for(j=1; j<=n; j++)
        {
            k=mp[j].size();
            for(l=0; l<k; l++)
            {
                v=busy[mp[j][l]]-busy[j];
                v=v*v*v;
                if (lvl[j]!=inf && (lvl[j] + v) < lvl[mp[j][l]])
                    {
                        lvl[mp[j][l]] = lvl[j] + v;
                        f=true;
                    }
            }
        }
        if(f==false)
            break;
    }
    for(j=1; j<=n; j++)
    {
        k=mp[j].size();
        for(l=0; l<k; l++)
        {
            v=busy[mp[j][l]]-busy[j];
            v=v*v*v;
            if (lvl[j] + v < lvl[mp[j][l]])
                    lvl[mp[j][l]] = inf;
        }
    }

}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int test,t,i,r,u,v;

    scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%d",&busy[i]);
        scanf("%d",&r);
        for(i=1; i<=r; i++)
        {
            scanf("%d %d",&u,&v);
            mp[u].push_back(v);
        }
        dij(1);
        scanf("%d",&u);
        printf("Case %d:\n",t);
        for(i=1; i<=u; i++)
        {
            scanf("%d",&v);
            if(lvl[v]<3 || lvl[v]>=inf)
                printf("?\n");
            else
                printf("%d\n",lvl[v]);
        }
        mp.clear();
    }
    return 0;
}
