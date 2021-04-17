#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define ll long long
#define LIMIT 10000000
bool flag[LIMIT+205];
int prime[665000],k;
void primegen()
{
    int sq=sqrt(LIMIT+200),i,j;
    flag[0]=flag[1]=1;
    flag[2]=0;
    k=0;
    prime[k++]=2;
    for(i=4; i<=LIMIT+200; i+=2)
        flag[i]=1;
    for(i=3; i<=LIMIT+200; i+=2)
    {

        if(flag[i]==1)
            continue;
        prime[k++]=i;
        if(i<=sq)
        {
            for(j=i*i; j<=LIMIT+200; j+=i+i)
            {
                flag[j]=1;
            }
        }
    }
    //cout<<prime[k-1]<<endl;
    return;
}
int main()
{
    int t,test,i;
    ll ans,x,c,sq;
    primegen();
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%lld",&x);
        sq=sqrt(x);
        ans=1;
        c=i=0;
        while(x>1)
        {
            while(x%prime[i]==0)
            {
                c++;
                x/=prime[i];
            }
            ans*=((2*c)+1);
            c=0;
            i++;
            if(prime[i]>sq && x>1)
            {
                x=1;
                ans*=3;
            }
        }
        //cout<<ans<<endl;
        ans++;
        ans/=2;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
