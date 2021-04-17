#include <bits/stdc++.h>
using namespace std;
struct node
{
    bool f[21];
    int now=0,see=0;
};
map<int,node> mp;
int l[21];
deque<int> q;
deque<int> ::iterator it;
int main()
{
    long long t,test,n,m,i,sum,mark,vis,v,x;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&m);
        mark=n*m;
        vis=sum=x=0;
        for(i=1; i<=n; i++)
            q.push_back(i);
        //cout<<"qsize= "<<q.size()<<endl;
        for(i=1; i<=m; i++)
        {
            sum+=5;
            if(!q.empty())
            {

                v=q.front();

                if(mp[i].f[v]==0)
                {
                    if(mp[i].now!=0 && l[mp[i].now]!=m)
                    {
                        q.push_back(mp[i].now);
                    }
                    if(mp[i].now==0)
                        x++;

                    mp[i].see++;
                    mp[i].now=v;

                    mp[i].f[v]=1;
                    vis++;
                    l[v]++;
                    q.pop_front();
                }
                else if(mp[i].see!=n)
                {
                    if(mp[i].now!=0)
                    {
                        if(l[mp[i].now]!=m)
                            q.push_back(mp[i].now);
                        mp[i].now=0;
                        x--;
                    }
                    for(it=q.begin();it!=q.end();it++)
                    {
                        if(mp[i].f[*it]==0)
                        {
                            mp[i].now=*it;
                            mp[i].f[*it]=1;
                            x++;
                            vis++;
                            l[*it]++;
                            q.erase(it);
                            break;
                        }
                    }
                }
                else if(mp[i].now!=0)
                {
                    if(l[mp[i].now]!=m)
                        q.push_back(mp[i].now);
                    mp[i].now=0;
                    x--;
                }
            }
            else if(mp[i].now!=0)
            {
                if(l[mp[i].now]!=m)
                    q.push_back(mp[i].now);
                mp[i].now=0;
                x--;
            }


            if(i==m)
                i=0;
            if(vis==mark && x==0)
                break;
            //cout<<"vis= "<<vis<<" qfront= "<<q.front()<<endl;
        }
        printf("Case %lld: %lld\n",t,sum);
        mp.clear();
        q.clear();
        memset(l,0,sizeof(l));
    }
    return 0;
}
