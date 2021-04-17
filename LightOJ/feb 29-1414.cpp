#include <bits/stdc++.h>

int main()
{
    long long year1,year2,ans;

    int t,test,day1,day2,x,y;

    char month1[11],month2[11];

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf(" %s %d, %lld",month1,&day1,&year1);
        scanf(" %s %d, %lld",month2,&day2,&year2);

        if(!strcmp(month1,"January")|| !strcmp(month1,"February"))
            x=0;
        else
            x=1;

        if(!strcmp(month2,"January")|| (!strcmp(month2,"February") && day2<29))
            y=0;
        else
            y=1;

        if(x!=0)
            year1++;
        if(y==0)
            year2--;

        ans=year2/4-(year1-1)/4-year2/100+(year1-1)/100+year2/400-(year1-1)/400;

        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
