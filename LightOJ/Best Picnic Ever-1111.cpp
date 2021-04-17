#include <bits/stdc++.h>
using namespace std;
map < int, vector <int> > mp;
map < int, int > city;
map <int, int > f;
map <int, int > g;
int k,c;

void look(int x, int sum)
{
    f[x]=1;

    city[x]+=sum;

    int i, z=mp[x].size();

    for(i=0; i<z; i++)
    {
        if(f[mp[x][i]]==0)
            look(mp[x][i], sum);
    }
}

int main()
{
    int test, t, n, m, u, v, i, j, x;

    scanf("%d", &test);

    for(t=1; t<=test; t++)
    {
        scanf("%d %d %d", &k, &n, &m);

        for(i=0; i<k; i++)
        {
            scanf("%d", &v);
            g[v]++;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            mp[u].push_back(v);
        }

        for(i=1; i<=n; i++)
        {
            if(g[i]>0)
            {
                f.clear();
                look(i,g[i]);
            }
        }
        c=0;
        for(i=1;i<=n;i++)
        {
            if(city[i]==k)
                c++;
        }
        printf("Case %d: %d\n", t, c);
        mp.clear();
        city.clear();
        g.clear();
    }
    return 0;
}
