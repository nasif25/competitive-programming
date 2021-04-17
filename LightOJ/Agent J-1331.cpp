#include <bits/stdc++.h>
using namespace std;

int main()
{
int t,test;
double r1,r2,r3,a,b,c,theta,area1,area2,area3,areat,arear,h,l,s;

scanf("%d",&test);

for(t=1;t<=test;t++)
{
scanf("%lf %lf %lf",&r1,&r2,&r3);

a=r1+r2;
b=r2+r3;
c=r3+r1;



theta=acos((a*a+c*c-b*b)/(2*a*c));
areat=.5*a*c*sin(theta);
s=r1*theta;
area1=s*r1/2;

theta=acos((a*a-c*c+b*b)/(2*a*b));
s=r2*theta;
area2=s*r2/2;

theta=acos((-a*a+c*c+b*b)/(2*b*c));
s=r3*theta;
area3=s*r3/2;

arear=areat-area1-area2-area3;

printf("Case %d: %.9lf\n",t,arear);

}
return 0;
}
