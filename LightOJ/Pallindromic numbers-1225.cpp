#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[12];
    int i,j,k,o,n,t,l,m;

    scanf("%d",&n);
    for(t=1;t<=n;t++)
    {
        scanf(" %s",a);
        l=strlen(a);
        m=l/2;
        if(l%2==0)
            k=m;
        else
            k=m+1;

        for(j=0,o=l-1;j<m && o>=k;j++,o--)
        {
            if(a[j]!=a[o])
            {
                m=-1;
                break;
            }
        }
        printf("Case %d: ",t);
        if(m==-1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
