#include <bits/stdc++.h>

using namespace std;
int marka[27],markb[27];

int main()
{
    int t,test,l,j,flag;
    char s[110];

    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        flag=0;

        scanf(" %[^\n]",s);
        l=strlen(s);


        for(j=0; j<l; j++)
        {
            if(('A'<=s[j] && s[j]<='Z') || ('a'<=s[j] && s[j]<='z'))
            {
                if('A'<=s[j] && s[j]<='Z')
                    s[j]+=32;

                marka[s[j]-97]++;
            }
        }

        scanf(" %[^\n]",s);
        l=strlen(s);

        for(j=0; j<l; j++)
        {
            if(('A'<=s[j] && s[j]<='Z') || ('a'<=s[j] && s[j]<='z'))
            {
                if('A'<=s[j] && s[j]<='Z')
                    s[j]+=32;

                markb[s[j]-97]++;
            }
        }
        for(j=0;j<26;j++)
        {
            if(marka[j]!=markb[j])
                flag=1;

            marka[j]=0;
            markb[j]=0;
        }
        if(flag==1)
            printf("Case %d: No\n",t);
        else
            printf("Case %d: Yes\n",t);
    }
    return 0;
}
