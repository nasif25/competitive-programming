#include <bits/stdc++.h>
using namespace std;

int stm(char monthS[])
{
    if (strcmp(monthS, "January") == 0)
        return 1;
    if (strcmp(monthS, "February") == 0)
        return 2;
    if (strcmp(monthS, "March") == 0)
        return 3;
    if (strcmp(monthS, "April") == 0)
        return 4;
    if (strcmp(monthS, "May") == 0)
        return 5;
    if (strcmp(monthS, "June") == 0)
        return 6;
    if (strcmp(monthS, "July") == 0)
        return 7;
    if (strcmp(monthS, "August") == 0)
        return 8;
    if (strcmp(monthS, "September") == 0)
        return 9;
    if (strcmp(monthS, "October") == 0)
        return 10;
    if (strcmp(monthS, "November") == 0)
        return 11;
    if (strcmp(monthS, "December") == 0)
        return 12;
    return -1;
}

int leap(long long year)
{
    int mark;
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
                mark=1;
            else
                mark=0;
        }
        else
            mark=1;
    }
    else
        mark=0;

    return mark;
}

int main()
{
    char month1[11],month2[11],mlist[13][11]= {"January","February","March","April","May","June","July","August","Septempber","October","November","December"};
    long long test,t,day1,day2,x,y,a,b,l;
    long long mark,year1,year2,i,j,k,m,n,flag=1,ans;


    long long mS, dS, yS, mE, dE, yE;
    char mStr[20];

    for(i=2000; i<=2005; i++)
    {
        year1=i;
        yS=i;
        cout<<year1<<endl<<yS<<endl;
        for(j=i; j<=2005; j++)
        {
            year2=j;
            yE=j;
            cout<<year2<<endl<<yE<<endl;
            for(k=0; k<3; k++)
            {
                //month1=mlist[k];
                mS = stm(mlist[k]);

                for(l=k; l<3; l++)
                {
                    //month2=mlist[l];
                    mE = stm(mlist[l]);

                    for(m=28; m<=30; m++)
                    {
                        a=leap(i);
                        if(a==1 && k==1 && m>29)
                            continue;
                        if(a==0 && k==1 && m>28)
                            continue;
                        day1=m;
                        dS=m;

                        for(n=28; n<=30; n++)
                        {
                            b=leap(i);
                            if(b==1 && k==1 && n>29)
                                continue;
                            if(b==0 && k==1 && n>28)
                                continue;
                            day2=n;
                            dE=n;

                            x=strcmp(month1,"January");
                            if(x!=0)
                                x=strcmp(month1,"February");

                            y=strcmp(month2,"January");
                            if(y!=0)
                            {
                                y=strcmp(month2,"February");

                                if(y==0)
                                {
                                    if(day2==29)
                                        y=1;
                                    else
                                        y=0;
                                }
                            }

                            if(year1==year2)
                            {
                                if(x==1)
                                    mark=0;
                                else if(y==0)
                                    mark=0;
                                else
                                    mark=a;
                            }
                            else
                            {
                                mark=(year2/4)-(year1/4)-(year2/100)+(year1/100)+(year2/400)-(year1/400);

                                if(a==1 && x==0)
                                    mark++;
                                if(b==1 && y==0)
                                    mark--;
                            }


                            if (mS > 2)
                                yS++;
                            if (mE < 2 || (mE == 2 && dE < 29))
                                yE--;

                            ans = yE / 4 - (yS - 1) / 4;
                            ans -= yE / 100 - (yS - 1) / 100;
                            ans += yE / 400 - (yS - 1) / 400;

                            cout<<mark<<endl;
                            cout<<ans<<endl;
                            if(ans!=mark)
                                printf("%s %lld, %lld\n%s %lld, %lld\n\n",mlist[k], day1, year1, mlist[l], day2, year2);


                        }
                    }
                }
            }
        }
    }


    /*scanf("%d",&test);

    for(t=1; t<=test; t++)
    {
        scanf(" %s %d, %lld",month1,&day1,&year1);
        scanf(" %s %d, %lld",month2,&day2,&year2);

        a=leap(year1);
        b=leap(year2);


        printf("Case %d: %lld\n",t,mark);
    }*/
    return 0;
}
