#include <bits/stdc++.h>

int main()
{
    int i=1,t,n;
    long long sum,num;
    char line[10];

    scanf("%d",&t);

    while(i<=t)
    {
        scanf("%d",&n);
        printf("Case %d:\n",i);
        sum=0;
        while(n--)
        {
            scanf("%s",line);
            if(line[0]=='d')
            {
                scanf("%lld",&num);
                sum+=num;
            }
            else
                printf("%lld\n",sum);
        }
        i++;
    }
    return 0;
}
