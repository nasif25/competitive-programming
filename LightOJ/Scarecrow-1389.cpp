#include <bits/stdc++.h>
int main(){
    int test,n,i,t,mark;
    char a[105];

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        scanf("%s",a);
        mark=0;
        for(i=0;i<n;i++)
        {
            if(a[i]=='.')
            {
                mark++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",t,mark);
    }
    return 0;
}
