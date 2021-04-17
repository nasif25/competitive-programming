#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    char g;
    string s,h,d="http://www.lightoj.com/",com;
    stack <string> f,b;

    scanf("%d",&t);
    getchar();
    for(i=1; i<=t; i++)
    {
        cin>>com;
        getchar();
        printf("Case %d:\n",i);
        while(com!="QUIT")
        {
            if(com=="QUIT")
                continue;
            else if(com=="VISIT")
            {
                if(b.empty()==true)
                    s=d;
                b.push(s);

                cin>>s;
                getchar();
                cout<<s<<endl;
                while(f.empty()==false)
                    f.pop();
            }
            else if(com=="BACK")
            {
                if(b.empty()==true)
                    printf("Ignored\n");
                else
                {
                    f.push(s);
                    s=b.top();
                    cout<<s<<endl;
                    b.pop();
                }
            }
            else if(com=="FORWARD")
            {
                if(f.empty()==true)
                    printf("Ignored\n");
                else
                {
                    //if(b.empty()==true)
                        //b.push(d);
                    b.push(s);

                    s=f.top();
                    cout<<s<<endl;
                    f.pop();
                }
            }
            //cin>>g;
            cin>>com;
            getchar();
        }
        while(b.empty()==false)
                    b.pop();
        while(f.empty()==false)
                    f.pop();
    }
    return 0;
}
