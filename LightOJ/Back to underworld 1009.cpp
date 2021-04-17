#include <bits/stdc++.h>
using namespace std;
map <int,vector <int> > mp;
map <int,vector <int> > ::iterator it;
map <int,int> lvl,p;
deque <int> q;
set <int> a[2];

void bfs(int src)
{
    int i,z,v;
    lvl[src]=1;
    p[src]=1;
    a[p[src]].insert(src);
    q.push_back(src);

    while(!q.empty())
    {
        v=q.front();
        q.pop_front();
        z=mp[v].size();
        for(i=0;i<z;i++)
        {
            if(lvl[mp[v][i]]==0)
            {
                lvl[mp[v][i]]=lvl[v]+1;
                p[mp[v][i]]=(p[v]+1)%2;
                q.push_back(mp[v][i]);
                a[p[mp[v][i]]].insert(mp[v][i]);
            }
        }
    }
}
int main()
{
    int test,t,n,i,j,u,v,hi;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        hi=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            mp[u].push_back(v);
            mp[v].push_back(u);
            j=max(u,v);
            if(j>hi)
                hi=j;
        }
        j=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(lvl[it->first]==0)
                {
                    bfs(it->first);
                    j+=max(a[0].size(),a[1].size());
                    a[0].clear();
                    a[1].clear();
                }
        }
        printf("Case %d: %d\n",t,j);
        mp.clear();
        lvl.clear();
        p.clear();
        q.clear();
    }
    return 0;
}
