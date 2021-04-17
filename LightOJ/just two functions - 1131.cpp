#include <bits/stdc++.h>
using namespace std;
#define mat_size 6
#define ll long long

ll mod, col_num = mat_size, row_num = mat_size;
ll mat[mat_size][mat_size], temp[mat_size][mat_size], res[mat_size][mat_size];

void matpower(long long pwr)
{
    long long i, j, k, s;

    if (pwr == 0)
    {
        for (i = 0; i < row_num; i++)
            for (j = 0; j < col_num; j++)
            {
                if (i != j)
                    res[i][j] = 0;
                else res[i][j] = 1;
            }
        return ;
    }

    matpower(pwr/2);

    for (i = 0; i < col_num; i++)
        for (j = 0; j < row_num; j++)
            temp[i][j] = res[i][j];

    for (i = 0; i < col_num; i++)
        for (j = 0; j < row_num; j++)
        {
            s = 0;
            for (k = 0; k < row_num; k++)
                s = (s + (temp[i][k]*temp[k][j])%mod)%mod;
            res[i][j] = s;
        }

    if(pwr%2 == 1)
    {
        for (i = 0; i < row_num; i++)
            for (j = 0; j < row_num; j++)
                temp[i][j] = res[i][j];

        for (i = 0; i < row_num; i++)
            for (j = 0; j < col_num; j++)
            {
                s = 0;
                for (k = 0; k < col_num; k++)
                    s = (s + (mat[i][k]*(temp[k][j]))%mod)%mod;
                res[i][j] = s;
            }
    }
}

int main ()
{
    ll t, test, i, j, x, a1, b1, c1, a2, b2, c2, f, f0, f1, f2, g, g0, g1, g2, q, v;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {

        scanf("%lld %lld %lld",&a1,&b1,&c1);
        scanf("%lld %lld %lld",&a2,&b2,&c2);
        scanf("%lld %lld %lld",&f0,&f1,&f2);
        scanf("%lld %lld %lld",&g0,&g1,&g2);
        scanf("%lld",&mod);


        mat[0][0] = a1;
        mat[0][1] = b1;
        mat[0][5] = c1;
        mat[1][0] = 1;
        mat[2][1] = 1;
        mat[3][2] = c2;
        mat[3][3] = a2;
        mat[3][4] = b2;
        mat[4][3] = 1;
        mat[5][4] = 1;        /* declaring the base matrix by putting value in mat array */

        scanf("%lld",&q);
        printf("Case %lld:\n",t);

        while(q--)
        {
            scanf("%lld",&v);

            if(v>2)
            {
                matpower(v-2);
                f = ((((((res[0][0]*f2)%mod+(res[0][1]*f1)%mod)%mod+(res[0][2]*f0)%mod)%mod+(res[0][3]*g2)%mod)%mod+(res[0][4]*g1)%mod)%mod+(res[0][5]*g0)%mod)%mod;
                g = ((((((res[3][0]*f2)%mod+(res[3][1]*f1)%mod)%mod+(res[3][2]*f0)%mod)%mod+(res[3][3]*g2)%mod)%mod+(res[3][4]*g1)%mod)%mod+(res[3][5]*g0)%mod)%mod;

            }
            else if(v==2)
            {
                f = f2%mod;
                g = g2%mod;
            }
            else if(v==1)
            {
                f = f1%mod;
                g = g1%mod;
            }
            else
            {
                f = f0%mod;
                g = g0%mod;
            }

            printf("%lld %lld\n", f, g);
        }
        // Now, res array will have mat^5
    }
    return 0;
}
