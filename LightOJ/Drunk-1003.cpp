#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define msz 4
#define cn 3
#define rn 3
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

map<ll, vector<ll> > mp;
map<string, ll> inx;
map<ll, ll> indeg;
vector<string> sl, top;
priority_queue <ll, vector<ll>, greater<ll> > pq;


void topsrt()
{
    ll i, u, j;

    map<ll, ll> :: iterator it;

    for(it=indeg.begin(); it!=indeg.end(); it++)
    {
        //cout<<it->vv<<" "<<it->uu<<endl;
        if(it->vv==0)
        {
            pq.push(it->uu);
        }
    }
    //cout<<pq.size()<<endl;

    while (!pq.empty())
    {
        u = pq.top();
        pq.pop();
        top.pb(sl[u]);

        for (i=0; i < mp[u].size(); i++)
        {
            // If in-degree becomes zero, add it to queue
            if (--indeg[mp[u][i]] == 0)
                pq.push(mp[u][i]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(1);
    string s, u, v;
    ll tc, test, i, k, m;

    cin>>test;

    for(tc=1; tc<=test; tc++)
    {
        cin>>m;
        sl.pb("-");

        for(i=0, k=1; i<m; i++)
        {
            cin>>u>>v;

            if(inx[u]==0)
                {
                    inx[u]=k++;
                    sl.pb(u);
                    indeg[k-1]=0;
                }
            if(inx[v]==0)
                {
                    inx[v]=k++;
                    sl.pb(v);
                    indeg[k-1]=0;
                }

            //cout<<sl[k-2]<<endl;

            mp[inx[u]].pb(inx[v]);
            indeg[inx[v]]++;
        }

        topsrt();

        cout<<"Case "<<tc<<": ";

        if(top.size()==k-1)
            cout<<"Yes\n";
        else
            cout<<"No\n";

        mp.clear();
        indeg.clear();
        inx.clear();
        sl.clear();
        top.clear();
    }
    return 0;
}

