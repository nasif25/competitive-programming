#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second

deque < pair<int,int> > q;
int cell[21][21],vis[21][21],h,w,sum;
int fx[]={-1,1,0,0},fy[]={0,0,1,-1};

void bfs(int sx, int sy)
{
    int tx,ty,i,j,k;
    pii top;

    cell[sx][sy]=0;
    q.push_back(pii(sx,sy));

    while(!q.empty())
    {
        top=q.front();
        q.pop_front();
        for(i=0;i<4;i++)
        {
            tx=top.uu+fx[i];
            ty=top.vv+fy[i];
            if(tx>=0 && tx<w && ty>=0 && ty<h && cell[tx][ty]==INT_MAX)
			{
			    cell[tx][ty]=cell[top.uu][top.vv]+1;
			    //cout<<"after "<<tx<<" "<<ty<<" "<<cell[top.uu][top.vv]<<" "<<cell[tx][ty]<<endl;
				q.pb(pii(tx,ty));
			}
        }
    }
}

int main()
{
   int t, test, i, j, u, v, u1, u2, u3, v1, v2, v3, ans;
   char c;

   scanf(" %d",&test);

   for(t=1;t<=test;t++)
   {
       scanf("%d %d",&w,&h);

       for(i=0;i<w;i++)
       {
           for(j=0;j<h;j++)
           {
               scanf(" %c",&c);

               if(c=='#' || c=='m')
                    vis[i][j]=-1;
                else if(c=='a')
                {
                    vis[i][j]=INT_MAX;
                    u1=i;
                    v1=j;
                }
                else if(c=='b')
                {
                    vis[i][j]=INT_MAX;
                    u2=i;
                    v2=j;
                }
                else if(c=='c')
                {
                    vis[i][j]=INT_MAX;
                    u3=i;
                    v3=j;
                }
                else if(c=='h')
                {
                    vis[i][j]=INT_MAX;
                    u=i;
                    v=j;
                }
                else
                    vis[i][j]=INT_MAX;

                cell[i][j]=vis[i][j];
           }
           //getchar();
       }

       ans=0;

       bfs(u1,v1);
       //cout<<cell[u][v]<<endl;
       ans=max(ans,cell[u][v]);

       for(i=0;i<w;i++)
       {
           for(j=0;j<h;j++)
           {
               cell[i][j]=vis[i][j];
           }
       }
       bfs(u2,v2);
       //cout<<cell[u][v]<<endl;
       ans=max(ans,cell[u][v]);

       for(i=0;i<w;i++)
       {
           for(j=0;j<h;j++)
           {
               cell[i][j]=vis[i][j];
           }
       }
       bfs(u3,v3);
       //cout<<cell[u][v]<<endl;
       ans=max(ans,cell[u][v]);

       printf("Case %d: %d\n", t, ans);
   }
   return 0;
}
