#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=1,t,flag,mark,zero,one,p,j,k,z;
    long long n,sum,num,x,tem;
    double d;
    char bin[34];

    scanf("%d",&t);
    while(i<=t)
    {
        scanf("%lld",&n);
        x=n;
        sum=j=z=zero=one=flag=num=p=0;

        while(1)
        {
            mark=x%2;
            bin[j++]=mark+48;

            if(flag==0)
            {
                if(mark==0)
                {
                    flag=1;
                    p=one;
                }
                else
                    flag=2;
            }
            if(mark==0)
            {
                zero++;
                if(flag==1 && one>p)
                    z=1;
            }
            else
                one++;

            //cout<<bin[j-1]<<endl;
            x/=2;

            if(x==0)
                break;
        }

        if(one==1)
            num=n*2;
        else if(zero==0)
        {
            bin[j-1]='0';
            bin[j]='1';
            for(k=0; k<=j; k++)
            {
                if(bin[k]=='1')
                {
                    d=pow(2.0,(double)k);
                    tem=(long long)d;
                    num+=tem;
                }
            }
        }
        else if(flag!=1)
        {
            for(k=0; k<j; k++)
            {
                if(bin[k]=='0' && flag==2)
                {
                    //bin[k-1]--;
                    num-=tem;
                    bin[k]++;
                    flag=3;
                }
                if(bin[k]=='1')
                {
                    d=pow(2.0,(double)k);
                    tem=(long long)d;
                    num+=tem;
                }
            }
        }
        else if(z==0)
        {
            p=one-1;
            for(k=0; k<one; k++)
            {
                if(k==p)
                    k=k+zero+1;
                d=pow(2.0,(double)k);
                tem=(long long)d;
                num+=tem;
            }
        }
        else
        {
            zero=one=p=0;
            for(k=0; k<j; k++)
            {

                if(bin[k]=='1')
                    one++;
                if(bin[k]=='0' && one>0 && p==0)
                {
                    bin[k]='1';
                    one--;
                    //bin[k-1]='0';
                    for(p=0; p<one; p++)
                    {
                        d=pow(2.0,(double)p);
                        tem=(long long)d;
                        num+=tem;
                        //cout<<num<<endl;
                    }
                    p=2;
                }
                if(bin[k]=='1' && p==2)
                {
                    d=pow(2.0,(double)k);
                    tem=(long long)d;
                    num+=tem;
                }
            }
        }

        printf("Case %d: ",i);
        //cout<<j<<endl;
        //cout<<j<< "\n" << bin[3] << " " << bin[2] << " " << bin[1] << " " << bin[0] << endl;
        printf("%lld\n",num);
        //cout<<endl;

        i++;
    }

    return 0;
}

