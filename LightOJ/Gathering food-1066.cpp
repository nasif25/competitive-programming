#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define uu first
#define vv second
deque <pii> q;
int fx[]= {0,0,1,-1},fy[]= {1,-1,0,0},node,vis,path,n,lvl[27][12][12];
char cell[12][12], c='A';

void bfs( pii src, int k)
{

    k++;
    vis++;
    lvl[k][src.uu][src.vv]=1;
    q.push_back(src);
    int i,tx,ty,l=0,z;
    while(!q.empty())
    {
        src=q.front();
        q.pop_front();
        for(i=0; i<4; i++)
        {
            tx=src.uu+fx[i];
            ty=src.vv+fy[i];

            if(cell[tx][ty]!='#' && tx>=1 && tx<=n && ty>=1 && ty<=n && lvl[k][tx][ty]==0)
            {
                if(cell[tx][ty]=='.'||cell[tx][ty]<=c+k)
                {
                    z=lvl[k][src.uu][src.vv];
                    if(cell[tx][ty]==c+k)
                    {
                        k++;
                        vis++;
                        l=z;
                        q.clear();
                        lvl[k][tx][ty]=z+1;
                        q.push_back(pii(tx,ty));
                        break;
                    }
                    //cout<<k<<" "<<tx<<" "<<ty<<" "<<cell[tx][ty]<<" "<<vis<< " "<<l<<" "<<z+1<<endl;
                    lvl[k][tx][ty]=z+1;
                    q.push_back(pii(tx,ty));
                }
            }
            if(vis==node)
                break;
        }
        if(vis==node)
            break;
    }
    path=l;
}

int main()
{
    int t, test, i, j;
    pii x;
    scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        getchar();
        scanf("%d",&n);
        getchar();
        node=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%c",&cell[i][j]);
                if(cell[i][j]=='A')
                {
                    x.uu=i;
                    x.vv=j;
                }
                if('A'<=cell[i][j] && cell[i][j]<='Z')
                    node++;
            }
            getchar();
        }
        vis=path=0;

        bfs(x,0);

        if(vis==node)
            printf("Case %d: %d\n",t,path);
        else
            printf("Case %d: Impossible\n",t);
        memset(lvl,0,sizeof(lvl));
        q.clear();
    }
    return 0;
}
