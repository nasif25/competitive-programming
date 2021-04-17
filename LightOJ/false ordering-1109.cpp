#include <bits/stdc++.h>
using namespace std;
int prime[1005],divs[1005],order[1005];
bool flag[1005];

void isprime()
{
    int i,j,k,x,sq=int(sqrt(1000.0))+1;

    for(i=2,k=0; i<=sq; i+=2)
    {
        if(flag[i]==0)
        {
            prime[k++]=i;
            x=2*i;
            for(j=i*i; j<=1001; j+=x)
                flag[i*j]=1;

            if(i==2)
                i--;
        }
    }
}
void isdiv()
{
    int i,j,k,sq,mark,x,temp;
    divs[1]=order[1]=1,divs[2]=order[2]=2;
    for(i=3;i<=1000;i++)
    {
        sq=(int)sqrt((double)i)+1;
        mark=1,x=i;
        for(j=0;prime[j]<=sq;j++)
        {
            temp=1;
            while(x%prime[j]==0)
            {
                temp++;
                x/=prime[j];
            }
             mark*=temp;
        }
        if(x!=1)
            mark*=2;

        divs[i]=mark;
        order[i]=i;
        k=i;
        while(k!=1 && divs[k]<=divs[k-1] && order[k]>order[k-1])
        {
            divs[k-1]=divs[k]+divs[k-1]-(divs[k]=divs[k-1]);
            order[k-1]=order[k]+order[k-1]-(order[k]=order[k-1]);
            k--;
        }
    }
}
int main()
{
    isprime();
    isdiv();
    int test,i,j;
    scanf("%d",&test);

    for(int j=1;j<=test;j++)
    {
        scanf("%d",&i);
        printf("Case %d: %d\n",j,order[i]);
    }
    return 0;
}
