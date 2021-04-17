#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mod 4294967296
#define inf 1000000000
#define limit 100000040

unsigned int prime[5761460], mulprime[100005], a[(limit+1)/32+10], k;

void primegen()
{
    unsigned int i, j, sq=sqrt(limit), pm;

    sq=sqrt(limit);
    a[1/32] |= 1;

    for( j = 4; j <= limit; j += 2) {
				a[j/32] |= (1<<(j%32));
			}

    for (i = 3; i <= sq; i += 2) {
            //cout<<i/32<<" "<<(1LL<<(i%32))<<endl;
		if(!(a[i/32]&(1<<(i%32)))) {
			for( j = i * i; j <= limit; j += 2 * i) {
				a[j/32] |= (1<<(j%32));
			}
		}
	}

    k=0;
    mulprime[0]=1;
	prime[k++] = 2;
	pm=2;

	for ( i = 3; i <= limit; i += 2) {
	    //cout<<k-1<<" "<<prime[k-1]<<" "<<i<<" "<<i/32<<" "<<(1LL<<(i%32))<<endl;
		if(!(a[i / 32] & (1 << (i % 32)))) {
			{
			    prime[k++] = i;

			    pm*=i;
			    mulprime[(i/1000)+1]=pm;
			    //cout<<i<<" "<<mulprime[(i/1000)+1]<<endl;
			}
		}
	}
}

int main()
{
    primegen();
//    cout<<k-1<<" "<<prime[k-1]<<endl;

    unsigned int tc, test, i, n, x, ans, sq;

    scanf("%u", &test);

    for(tc=1;tc<=test;tc++)
    {
        scanf("%u", &n);

        ans=mulprime[n/1000];

        for(i=((n/1000)*1000)+1;i<=n;i++)
        {
            if(!(a[i / 32] & (1 << (i % 32))))
                {
                    ans*=i;
                    //cout<<i<<" "<<ans<<endl;
                }
        }

        sq=sqrt(n);
        for(i=0;prime[i]<=sq;i++)
            {
                x=n;
                x/=prime[i];

                while(x/prime[i])
                {
  //                cout<<x<<" "<<prime[i]<<endl;
                    ans=ans*prime[i];
                    x/=prime[i];
                    //cout<<x<<endl;
                }
            }
        printf("Case %u: %u\n", tc, ans);
    }

    return 0;
}
