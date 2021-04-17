
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
struct node
{
    ll ax, ay, bx, by, cx, cy, v;

    node(ll ax=0, ll ay=0, ll bx=0, ll by=0, ll cx=0, ll cy=0, ll v=0)
    {
        this->ax=ax;
        this->ay=ay;
        this->bx=bx;
        this->by=by;
        this->cx=cx;
        this->cy=cy;
        this->v=v;
    }
};
ll ar[11][11], vis[11][11][11][11][11][11];
ll fx[]= {0, 0, 1, -1};
ll fy[]= {1, -1, 0, 0};
ll tc, ans, n;

deque <node> dq;

void solve(ll ax, ll ay, ll bx, ll by, ll cx, ll cy)
{
    node z;
    pll p;
    ll v=0, i, tx1, tx2, tx3, ty1, ty2, ty3;
    bool f1, f2, f3;

    vis[ax][ay][bx][by][cx][cy]=tc;
    dq.pb(node(ax, ay, bx, by, cx, cy, v));

    while(!dq.empty())
    {
        z=dq.front();
        dq.ppf();
        if(ar[z.ax][z.ay]==1 && ar[z.bx][z.by]==1 && ar[z.cx][z.cy]==1)
        {
//            cout<<z.ax<< " "<<z.ay<<" "<<z.bx<<" "<<z.by<<" "<<z.cx<<" "<<z.cy<<" "<<z.v<<endl;
            ans=min(ans, z.v);
            while(!dq.empty())
            {
                dq.pop_front();
            }
            break;
        }

        for(i=0; i<4; i++)
        {
            f1=f2=f3=0;

            if(z.ax+fx[i]>0 && z.ax+fx[i]<=n && z.ay+fy[i]>0 && z.ay+fy[i]<=n)
            {
                if(ar[z.ax+fx[i]][z.ay+fy[i]]!=-1)
                {
                    f1=1;
                    tx1=z.ax+fx[i];
                    ty1=z.ay+fy[i];
                }
                else
                {
                    f1=0;
                    tx1=z.ax;
                    ty1=z.ay;
                }
            }
            else
            {
                f1=0;
                tx1=z.ax;
                ty1=z.ay;
            }
            if(z.bx+fx[i]>0 && z.bx+fx[i]<=n && z.by+fy[i]>0 && z.by+fy[i]<=n)
            {
                if(ar[z.bx+fx[i]][z.by+fy[i]]!=-1)
                {
                    f2=1;
                    tx2=z.bx+fx[i];
                    ty2=z.by+fy[i];
                }
                else
                {
                    f2=0;
                    tx2=z.bx;
                    ty2=z.by;
                }
            }
            else
            {
                f2=0;
                tx2=z.bx;
                ty2=z.by;
            }
            if(z.cx+fx[i]>0 && z.cx+fx[i]<=n && z.cy+fy[i]>0 && z.cy+fy[i]<=n)
            {
                if(ar[z.cx+fx[i]][z.cy+fy[i]]!=-1)
                {
                    f3=1;
                    tx3=z.cx+fx[i];
                    ty3=z.cy+fy[i];
                }
                else
                {
                    f3=0;
                    tx3=z.cx;
                    ty3=z.cy;
                }
            }
            else
            {
                f3=0;
                tx3=z.cx;
                ty3=z.cy;
            }
//                        cout<<tx1<<" "<<ty1<<" "<<tx2<<" "<<ty2<<" "<<tx3<<" "<<ty3<<endl;

            for(ll j=0; j<2; j++)
            {
                if(tx1==tx2 && ty1==ty2)
                {
                    tx1=z.ax;
                    ty1=z.ay;
                }
                if(tx1==tx3 && ty1==ty3)
                {
                    tx1=z.ax;
                    ty1=z.ay;
                }
                if(tx2==tx1 && ty2==ty1)
                {
                    tx2=z.bx;
                    ty2=z.by;
                    //cout<<tx2<<" "<<ty2<<" "<<z.bx<<" "<<z.by<<endl;

                }
                if(tx2==tx3 && ty2==ty3)
                {
                    tx2=z.bx;
                    ty2=z.by;
                    //cout<<tx2<<" "<<ty2<<" "<<z.bx<<" "<<z.by<<endl;
                }
                if(tx3==tx1 && ty3==ty1)
                {
                    tx3=z.cx;
                    ty3=z.cy;
                }
                if(tx3==tx2 && ty3==ty2)
                {
                    tx3=z.cx;
                    ty3=z.cy;
                }
            }

//            cout<<z.ax<< " "<<z.ay<<" "<<z.bx<<" "<<z.by<<" "<<z.cx<<" "<<z.cy<<" "<<z.v<<endl;
//            cout<<tx1<<" "<<ty1<<" "<<tx2<<" "<<ty2<<" "<<tx3<<" "<<ty3<<endl;
//
//            getchar();

            if(vis[tx1][ty1][tx2][ty2][tx3][ty3]!=tc)
            {
                vis[tx1][ty1][tx2][ty2][tx3][ty3]=tc;
                dq.pb(node(tx1, ty1, tx2, ty2, tx3, ty3, z.v+1));
            }
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll i, j, test;
    ll ax, ay, bx, by, cx, cy;


    char c;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf(" %c", &c);

                if(c=='#')
                    ar[i][j]=-1;
                else if(c=='X')
                    ar[i][j]=1;
                else
                {
                    ar[i][j]=0;
                    if(c=='A')
                    {
                        ax=i;
                        ay=j;
                    }
                    else if(c=='B')
                    {
                        bx=i;
                        by=j;
                    }
                    else if(c=='C')
                    {
                        cx=i;
                        cy=j;
                    }
                }
            }
        }
//        for(i=1; i<=n; i++)
//        {
//            for(j=1; j<=n; j++)
//            {
//                cout<<ar[i][j];
//            }
//            cout<<endl;
//        }
        ans=inf;
        solve(ax, ay, bx, by, cx, cy);

        if(ans==inf)
            printf("Case %lld: trapped\n", tc);
        else
            printf("Case %lld: %lld\n", tc, ans);
    }

    return 0;
}

