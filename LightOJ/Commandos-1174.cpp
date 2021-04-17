#include <bits/stdc++.h>
using namespace std;
map <int,vector<int> > mp;
int lvl[2][101];
deque<int> q;
int in,fin;
void bfs(int src,int k)
{
    lvl[k][src]=0;
    q.push_back(src);
    int i,z,v,x;

    while(!q.empty())
    {
        v=q.front();
        q.pop_front();
        z=mp[v].size();
        for(i=0;i<z;i++)
        {
            x=mp[v][i];
            if(lvl[k][x]==0 && x!=src)
            {
                lvl[k][x]=lvl[k][v]+1;
                q.push_back(x);
            }
        }
    }
}
int main()
{
    int t, test, n, r, i, u, v, ans, sum;

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        scanf("%d",&r);

        while(r--)
        {
            scanf("%d %d",&u,&v);
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        scanf("%d %d",&in,&fin);
        bfs(in,0);
        bfs(fin,1);
        ans=0;
        for(i=0;i<n;i++)
        {
            sum=lvl[0][i]+lvl[1][i];
            if(sum>ans)
                ans=sum;
        }
        printf("Case %d: %d\n",t,ans);
        mp.clear();
        memset(lvl,0,sizeof(lvl));
    }
    return 0;
}
