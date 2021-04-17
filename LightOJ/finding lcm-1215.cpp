#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 1000100
bool stat[1000101];
ll prime[500005];

void primegen()
{
    ll i, j, k, sq=sqrt(limit);

    k=0;
    stat[0]=stat[1]=1;
    prime[k++]=2;

    for(i=4; i<=limit; i+=2)
        stat[i]=1;

    for(i=3; i<=limit; i+=2)
    {
        if(stat[i]==0)
        {
            prime[k++]=i;
            if(i<=sq);
            {
                for(j=i*i; j<=limit; j+=(i+i))
                {
                    stat[j]=1;
                }
            }
        }
    }
    //cout<<prime[k-1]<<endl;
}

ll gcd(ll a, ll b)
{
    if(a%b==0)
        return b;

    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}

int main()
{
    ll tc, test, a, b, c, L, l1, n, m, l, x, y, i, j, c1, c2, sq, ans;

    primegen();

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld %lld", &a, &b, &L);

        l1=lcm(a,b);

        if(L%l1!=0)
            printf("Case %lld: impossible\n", tc);
        else
        {
            sq=sqrt((double)L);
            //cout<<sq<<endl;
            x=L;
            y=l1;
            ans=1;
            for(i=0; x>1 && prime[i]<=sq; i++)
            {
                c1=c2=0;
//                    cout<<x<<" "<<y<<" "<<ans<<endl;

                while(x%prime[i]==0)
                {
                    x/=prime[i];
                    c1++;
                }

                while(y%prime[i]==0)
                {
                    y/=prime[i];
                    c2++;
                }

                if(c1>c2)
                {
                    for(j=1; j<=c1; j++)
                        ans*=prime[i];
                }
                //cout<<i<<" "<<prime[i]<<" "<<x<<" "<<y<<" "<<c1<<" "<<c2<<" "<<ans<<endl;
            }
            if(x>1 && y%x!=0)
            {
                ans*=x;
            }

            printf("Case %lld: %lld\n", tc, ans);
//                cout<<lcm(ans, lcm(a,b))<<" "<<l1<<endl;
        }
    }

    return 0;
}


