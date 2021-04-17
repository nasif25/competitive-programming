#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,t,n,k,p,m,i,j,x,mark,z;
    bool flag,stat,stat2;
    set <int> s;
    set <int>:: iterator sit1,sit2;
    map <int,set<int> > take,reject;

    scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%d %d %d",&n,&m,&k);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=k; j++)
            {
                scanf("%d",&x);
                if(x>0)
                    take[i].insert(x);
                else
                    reject[i].insert(-1*x);
            }
        }
        scanf("%d",&p);
        for(z=1; z<=p; z++)
        {
            scanf("%d",&x);
            s.insert(x);
        }
        flag=mark=0;

        for(i=1; i<=n; i++)
        {
            stat=stat2=0;
            //for(sit1=s.begin(); sit1!=s.end(); sit1++)
            if(take.find(i)!=take.end())
            {

                for(sit2=take[i].begin(); sit2!=take[i].end(); sit2++)
                {
                    if(s.find(*sit2)!=s.end())
                    {
                        //cout<<*sit2<<endl;
                        stat=1;
                        stat2=1;
                        break;
                    }
                }
            }
            if(stat==0 && reject.find(i)!=reject.end())
            {
                for(sit2=reject[i].begin(); sit2!=reject[i].end(); sit2++)
                {
                    //            cout<<" "<<*sit2<<endl;
                    if(s.find(*sit2)==s.end())
                    {
                        stat=1;
                        break;
                    }
                }
            }
            //cout<<no<<" "<<reject[i].size()<<endl;
            if(stat==1||stat2==1)
                mark++;
        }

        if((p==0 && reject.size()==n)||mark==n)
            flag=1;

        if(flag==1)
            printf("Case %d: Yes\n",t);
        else
            printf("Case %d: No\n",t);

        take.clear();
        reject.clear();
        s.clear();
    }
    return 0;
}
