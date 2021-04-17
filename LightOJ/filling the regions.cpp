
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <malloc.h>
#include <ctime>
#include <list>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define ppf pop_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

char ar[52][52], now;
ll vis[52][52];
ll taken[52];
ll n, m, tc, f;
ll fx[]= {0, 1, 0, -1};
ll fy[]= {1, 0, -1, 0};

bool check(ll x, ll y)
{
    if(x<0 ||x>=n || y<0 || y>=m || vis[x][y] || ar[x][y]==now)
        return 0;

    return 1;
}

void bfs(ll x, ll y)
{
    memset(vis, 0, sizeof vis);
    ll k, i, j, tx, ty;
    queue<pll> q;

    for(i=0; i<n; i++)
    {
        if(ar[i][0]!=now)
        {
            vis[i][0]=1;
            q.push(pll(i, 0));
        }

        if(ar[i][m-1]!=now)
        {
            vis[i][m-1]=1;
            q.push(pll(i, m-1));
        }
    }

    for(i=0; i<m; i++)
    {
        if(ar[0][i]!=now)
        {
            vis[0][i]=1;
            q.push(pll(0, i));
        }
        if(ar[n-1][i]!=now)
        {
            vis[n-1][i]=1;
            q.push(pll(n-1, i));
        }
    }

    while(!q.empty())
    {
        i=q.front().uu;
        j=q.front().vv;

        q.pop();

        for(k=0; k<4; k++)
        {
            tx=i+fx[k];
            ty=j+fy[k];

            if(check(tx, ty))
            {
                vis[tx][ty]=1;
                q.push(pll(tx, ty));
            }
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(!vis[i][j])
            {
                ar[i][j]=now;
                vis[i][j]=1;
            }
        }
    }
}



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll test, i, j;

    scanf("%lld", &test);

    f=1;

    for(tc=1; tc<=test; tc++)
    {
        //cout<<tc<<" "<<test<<endl;
        scanf("%lld %lld", &n, &m);

        for(i=0; i<n; i++)
        {
            scanf("%s", ar[i]);
        }
        memset(taken, 0, sizeof taken);

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                now=ar[i][j];
                if(taken[now-'A']==0 && now!='.')
                {
                    taken[now-'A']=1;
                    //cout<<now<<endl;
                    bfs(i, j);
                }
            }
        }
        printf("Case %lld:\n", tc);

        for(i=0; i<n; i++)
        {
            printf("%s\n", ar[i]);
        }
        //getchar();
    }

    return 0;
}
