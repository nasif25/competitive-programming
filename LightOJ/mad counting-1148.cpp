#include <bits/stdc++.h>
using namespace std;

int check[1000005];

int main()
{
    int i=1,t,n;
    long long num[55],sum,maxm=0,temp,div,remain,j;
    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%d",&n);
        //for(j=0;j<maxm;j++)
            //check[num[j]]=0;

        sum=0,maxm=0;

        for(j=0; j<n; j++)
        {
            scanf("%lld",&num[j]);

            check[num[j]]++;

            if(num[j]>maxm)
                maxm=num[j];
        //cout<<check[num[j]]<<endl<<num[j]<<endl<<maxm<<endl;
        }
        //cout<<"maxm="<<maxm<<endl;
        for(j=0; j<=maxm; j++)
        {


            if(check[j]!=0)
            {
                div=j+1;
                temp=check[j]/div;
                //cout<<temp<<endl;
                temp*=div;
                //cout<<temp<<endl;
                remain=check[j]%div;
               // cout<<remain<<endl;
                if(remain>0)
                    temp+=div;

                //cout<<"temp"<<temp<<endl;
                sum+=temp;
                //cout<<"sum="<<sum<<endl;
                check[j]=0;
            }
            //cout<<"c"<<endl;
        }
        printf("Case %d: %lld\n",i,sum);
        i++;
    }
    return 0;
}
