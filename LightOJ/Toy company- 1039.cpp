#include <bits/stdc++.h>
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

ll vis[27][27][27], ans;
ll fx[]= {1, -1, 0, 0, 0, 0};
ll fy[]= {0, 0, 1, -1, 0, 0};
ll fz[]= {0, 0, 0, 0, 1, -1};
char st1[4], st2[4];

struct node
{
    ll x, y, z;

    node(ll x=0, ll y=0, ll z=0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

deque <node> dq;

void bfs()
{
    ll i, j, k, m;
    node top;

    vis[st1[0]-'a'][st1[1]-'a'][st1[2]-'a']=0;
    dq.pb(node(st1[0]-'a',st1[1]-'a',st1[2]-'a'));

    while(!dq.empty())
    {
        top=dq.front();
        dq.ppf();

        if(top.x==st2[0]-'a' && top.y==st2[1]-'a' && top.z==st2[2]-'a')
            ans=min(ans, vis[top.x][top.y][top.z]);

        for(m=0; m<6; m++)
        {
            i=(top.x+fx[m])%26;
            j=(top.y+fy[m])%26;
            k=(top.z+fz[m])%26;

            if(i<0)
                i+=26;
            if(j<0)
                j+=26;
            if(k<0)
                k+=26;

            if(vis[i][j][k]==-1)
            {
                vis[i][j][k]=vis[top.x][top.y][top.z]+1;
                dq.pb(node(i, j, k));
            }
        }
    }
}

int main()
{
    ll tc, test, i, j, k, l1, l2, l3, x, y, z, n;

    char a[27], b[27], c[27];

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf(" %s %s", st1, st2);

        scanf("%lld", &n);

        memset(vis, -1, sizeof(vis));

        while(n--)
        {
            scanf(" %s %s %s", a, b, c);

            l1=strlen(a);
            l2=strlen(b);
            l3=strlen(c);

            for(i=0; i<l1; i++)
            {
                for(j=0; j<l2; j++)
                {
                    for(k=0; k<l3; k++)
                    {
                        vis[a[i]-'a'][b[j]-'a'][c[k]-'a']=-inf;
                    }
                }
            }
        }
        ans=inf;

        if(vis[st1[0]-'a'][st1[1]-'a'][st1[2]-'a']==-1)
            bfs();

        if(ans==inf)
            printf("Case %lld: -1\n", tc);
        else
            printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}

