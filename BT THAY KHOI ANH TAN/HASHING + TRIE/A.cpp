#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
const int base = 256;
const int MS = 2;
ll Pow[MS+5][MM],hashA[MS+5][MM],hashB[MS+5];
string A,B;

ll getHash(int i,int j,int k)
{
    return (hashA[k][j] - hashA[k][i-1] * Pow[k][j-i+1] % MOD[k] + MOD[k]) % MOD[k];
}

void solve()
{
    cin >> A >> B;
    int n = A.size(), m = B.size();
    A = ' ' + A;
    B = ' ' + B;
    for(int j = 0;j < MS;j++) {
        Pow[j][0] = 1;

        for(int i = 1;i <= n;i++) 
            Pow[j][i] = (Pow[j][i-1] * base) % MOD[j];
    }

    for(int j = 0;j < MS;j++) {

        for(int i = 1;i <= n;i++)
            hashA[j][i] = (hashA[j][i-1] * base + A[i] - '0' + 1) % MOD[j];

        for(int i = 1;i <= m;i++)
            hashB[j] = (hashB[j] * base + B[i] - '0' + 1) % MOD[j];
    }

    for(int i = 1;i <= n-m+1;i++) {

        bool ok = 1;

        for(int j = 0;j < MS;j++) 
            if(getHash(i,i+m-1,j) != hashB[j]) ok = 0;

        if(ok) cout << i << ' ';

    }


}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}