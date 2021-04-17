#include <bits/stdc++.h>
using namespace std;

deque < pair<int,int> > q;
int cell[21][21],visited[21][21],h,w,sum;
int fx[]={-1,1,0,0},fy[]={0,0,1,-1};

void bfs(int sx, int sy)
{
    int tx,ty,i,j,k;
   //pair<int,int> p,top;
   visited[sx][sy]=1;
    q.push_back(pair<int,int>(sx,sy));
    sum++;



    while(!q.empty())
    {
        pair<int,int>top=q.front();
        q.pop_front();
        for(i=0;i<4;i++)
        {
            tx=top.first+fx[i];
            ty=top.second+fy[i];
            if(tx>=0 and tx<h and ty>=0 and ty<w and cell[tx][ty]!=-1 and visited[tx][ty]==0)
			{
			    sum++;
				visited[tx][ty]=1;
				q.push_back(pair<int,int>(tx,ty));
			}
        }
    }
}

int main()
{
   int t,test,i,j,u,v;
   char c;

   scanf(" %d",&test);

   for(t=1;t<=test;t++)
   {
       scanf("%d %d",&w,&h);
       memset(cell,0,sizeof(cell));
       memset(visited,0,sizeof(visited));

       for(i=0;i<h;i++)
       {
           for(j=0;j<w;j++)
           {
               scanf(" %c",&c);
               if(c=='#')
                cell[i][j]=-1;
                else if(c=='@')
                {
                    u=i;
                    v=j;
                }
           }
       }
       sum=0;
       bfs(u,v);
       printf("Case %d: %d\n",t,sum);

       q.clear();
   }
   return 0;
}


