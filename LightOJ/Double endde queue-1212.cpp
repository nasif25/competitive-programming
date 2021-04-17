#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,x,j,n,m,flag;
    string s;
    deque <int> a;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        flag=0;
        scanf("%d %d",&n,&m);
        for(j=0; j<m; j++)
        {
            getchar();
            cin>>s;

            if(j==0)
                printf("Case %d:\n",i);

            if(s=="pushLeft")
            {
                scanf("%d",&x);
                if(flag==n)
                    printf("The queue is full\n");
                else
                {
                    a.push_front(x);
                    flag++;
                    printf("Pushed in left: %d\n",x);
                }
            }
            else if(s=="pushRight")
            {
                scanf("%d",&x);
                if(flag==n)
                    printf("The queue is full\n");
                else
                {
                    a.push_back(x);
                    flag++;
                    printf("Pushed in right: %d\n",x);
                }
            }
            else if(s=="popLeft")
            {
                if(a.empty()==true)
                    printf("The queue is empty\n");
                else
                {
                    x = a.front();
                    a.pop_front();
                    flag--;
                    printf("Popped from left: %d\n",x);
                }
            }
            else if(s=="popRight")
            {

                if(a.empty()==true)
                    printf("The queue is empty\n");
                else
                {
                    x = a.back();
                    a.pop_back();
                    flag--;
                    printf("Popped from right: %d\n",x);
                }
            }
        }
        a.clear();
    }
    return 0;
}
