#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,t,n,i,b[5],sum,j,flag;
    char c;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        int j=4;
        for(i=0; i<4; i++)
        {
            scanf("%d",&b[i]);
            if(i!=3)
                getchar();
        }

        flag=j=0;
        while(j<4)
        {
            getchar();
            sum=0;
            for(i=7; i>=0; i--)
            {
                scanf("%c",&c);
                if(c=='1')
                    sum+=pow(2,i);
            }
            if(sum!=b[j])
                flag=1;
            j++;
        }
        printf("Case %d: ",t);
        if(flag==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
