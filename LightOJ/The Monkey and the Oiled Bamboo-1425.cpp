#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    int t,test;
    long long n,hi1,hi2,i,j,m1,m2;

    scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld",&n);
        hi1=hi2=m1=m2=0;
        a[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]-a[i-1]>hi1)
            {
                m1=0;
                hi1=a[i]-a[i-1];
            }
            else if(a[i]-a[i-1]==hi1)
            {
                m1++;
                hi1++;
            }

            if(a[i]-a[i-1]>hi2 && a[i]-a[i-1]==hi1-1)
            {
                m2=0;
                hi2=a[i]-a[i-1];
            }
            else if(a[i]-a[i-1]==hi2)
                m2++;
        }
        //cout<<"hi1= "<<hi1<<"\nm1= "<<m1<<"\nhi2= "<<hi2<<"\nm2= "<<m2<<endl;
        if(m1==0 && m2!=0)
            hi1++;

        printf("Case %d: %lld\n",t,hi1);
    }
    return 0;
}
