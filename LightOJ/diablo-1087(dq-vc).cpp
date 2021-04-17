
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a1,i1=0;
    cin>>a1;
    while(i1<a1)
    {
        i1++;
        int a,b,c,d,i,j,k,l,m,n;
        cin>>n>>k;
        vector<int>v1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            v1.push_back(a);
        }
        char c1;
        printf("Case %d:\n",i1);
        for(i=0;i<k;i++)
        {
            getchar();
            scanf(" %c",&c1);
            if(c1=='c')
            {
                scanf("%d",&b);
                if(b>v1.size())
                    printf("none\n");
                else
                {
                    printf("%d\n",v1[b-1]);
                    v1.erase(v1.begin()+(b-1));
                }
            }
            if(c1=='a')
            {
                scanf("%d",&b);
                v1.push_back(b);
            }
        }

    }
    return 0;
}
