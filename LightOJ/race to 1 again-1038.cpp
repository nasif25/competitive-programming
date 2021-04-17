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
    double s;
    ll cnt;
    node()
    {
        s=0.0;
        cnt=0;
    }
}save[100005];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//      ios_base::sync_with_stdio(0);

    ll n, i, j, tc, test;

    double div, sum;

    save[1].s=0.0;

    for(i=2; i<=100000; i++)
    {
        sum=save[i].s;
        div=(double)(save[i].cnt+2);
        sum/=div;
        sum+=1.0;
        sum=sum*div/(div-1.0);
        save[i].s=sum;

//        if(i<=50)
//        cout<<i<<"= "<< save[i].s<<endl;

        for(j=i+i; j<=100000; j+=i)
            {
                save[j].s+=save[i].s;
                save[j].cnt++;
            }
    }
//    cout<<"ok1\n";

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);
        printf("Case %lld: %.9lf\n", tc, save[n]);
    }

    return 0;
}
