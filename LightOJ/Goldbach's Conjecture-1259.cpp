#include <bits/stdc++.h>
using namespace std;
#define LIMIT 10000000
bool flag[LIMIT+1];
int prime[664580],k;
void isprime()
{
    int i,j,sq=sqrt(LIMIT)+1;
    k=1;
    prime[0]=2;
    flag[0]=flag[1]=1;
    for(i=4; i<=LIMIT; i+=2)
        flag[i]=1;
    for(i=3; i<=LIMIT; i+=2)
    {
        if(flag[i]==1)
            continue;
        prime[k++]=i;
        if (i <= sq)
        {
            for(j=i*i; j<=LIMIT; j+=i+i)
                flag[j]=1;
        }
    }
}
int main()
{
    // freopen("in1.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int num,temp1,temp2,t,test,i,f;
    isprime();

    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        scanf("%d",&num);
//        if(num==0)
//            break;
        if(num==4)
        {
            printf("Case %d: 1\n",i);
            continue;
        }
        temp1=(num/2);
        if(temp1%2==0)
        {
            temp1--;
            temp2=temp1+2;
        }
        else
            temp2=temp1;
        //cout<<temp1<<endl;
        for(f=0;prime[f]<=temp1;f++);

        f--;
        t=0;
        temp1=prime[f--];
        temp2=num-temp1;
        while(1)
        {
            if(temp1<3 || temp2>num || f<0)
                break;
            if(flag[temp1]==0 && flag[temp2]==0)
                t++;
            //cout<<"1"<<endl;

            temp1=prime[f--];
            temp2=num-temp1;
        }
        printf("Case %d: %d\n",i,t);
    }
    return 0;
}
