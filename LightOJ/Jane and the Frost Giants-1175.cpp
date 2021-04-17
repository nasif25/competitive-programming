#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000
ll r, c;
char ar[202][202];
ll vis1[202][202], vis2[202][202], ans;
ll fx[]= {0, 0, 1, -1}, fy[]= {1, -1, 0, 0};
deque <pll> dq;

void bfs1()
{
    ll i, j, x, y;
    pll top;

    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            if(ar[i][j]=='F')
            {
                vis1[i][j]=0;
                dq.pb(pll(i, j));
            }
        }
    }

    while(!dq.empty())
    {
        top=dq.front();
        dq.pop_front();

        for(i=0; i<4; i++)
        {
            x=top.uu+fx[i];
            y=top.vv+fy[i];
            if(ar[x][y]!='#' && vis1[x][y]==-1)
            {
                vis1[x][y]=vis1[top.uu][top.vv]+1;
                dq.pb(pll(x, y));
            }
        }
    }
}

void bfs2(ll sx, ll sy)
{
    ll i, j, x, y;
    pll top;

    vis2[sx][sy]=0;
    dq.pb(pll(sx, sy));

    while(!dq.empty())
    {
        top=dq.front();
        dq.pop_front();

        if(top.uu==1 || top.uu==r)
            ans=min(ans, vis2[top.uu][top.vv]);
        else if(top.vv==1 || top.vv==c)
            ans=min(ans, vis2[top.uu][top.vv]);

        for(i=0; i<4; i++)
        {
            x=top.uu+fx[i];
            y=top.vv+fy[i];
            if(ar[x][y]!='#' && vis2[x][y]==-1 && vis2[top.uu][top.vv]+1<vis1[x][y])
            {
                vis2[x][y]=vis2[top.uu][top.vv]+1;
                dq.pb(pll(x, y));
            }
        }
    }
}

int main()
{
    ll tc, test, i, j, k, x, y;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &r, &c);

        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                scanf(" %c", &ar[i][j]);

                vis1[i][j]=vis2[i][j]=-1;

                if(ar[i][j]=='J')
                {
                    x=i;
                    y=j;
                }
            }
        }
        bfs1();

        ans=inf;

        bfs2(x, y);

        printf("Case %lld: ",tc);

        if(ans==inf)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n", ans+1);
    }
    return 0;
}

