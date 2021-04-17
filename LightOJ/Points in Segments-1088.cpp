#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000
ll a[100002],loclo,lochi;

void bin1(ll beg, ll end, ll v)
{
    ll mid;
//cout<<v<<endl;
    while(beg<=end)
    {
        mid=(beg+end)/2;
//        cout<<mid<<" "<<a[mid]<<" "<<beg<<" "<<a[beg]<<" "<<end<<" "<<a[end]<<endl;
        if(a[mid]>=v && mid<loclo)
        {
            loclo=mid;
        }

        if(a[mid]<v)
            beg=mid+1;
        if(a[mid]>=v)
            end=mid-1;
    }
}
void bin2(ll beg, ll end, ll v)
{
    ll mid;

    while(beg<=end)
    {
        mid=(beg+end)/2;
        //cout<<mid<<" "<<a[mid]<<" "<<beg<<" "<<a[beg]<<" "<<end<<" "<<a[end]<<endl;

        if(a[mid]<=v && mid>lochi)
        {
            lochi=mid;
        }

        if(a[mid]<=v)
            beg=mid+1;
        if(a[mid]>v)
            end=mid-1;
    }
}
int main()
{
    ll t, test, n, q, i, ans, u, v;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&q);

        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);

        printf("Case %lld:\n",t);

        while(q--)
        {
            scanf("%lld %lld",&u, &v);

            lochi=-1;
            loclo=inf;

            bin1(0,n-1,u);
            //cout<<loclo<<endl;
            bin2(0,n-1,v);
            //cout<<lochi<<endl;


            if(loclo==inf || lochi==-1)
                ans=0;
            else
            {
                ans=lochi-loclo+1;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

