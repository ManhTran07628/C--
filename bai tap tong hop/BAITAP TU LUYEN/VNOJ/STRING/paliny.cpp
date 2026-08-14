#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
const int base = 256;
const int ms = 2;
ll Pow[ms + 5][MM + 5];
ll hashA[ms + 5][MM + 5],hashB[ms + 5][MM + 5];
int n;
string A,B;

ll getHash(int l,int r,int k,ll hash[][MM + 5])
{
    return (hash[k][r] - hash[k][l-1] * Pow[k][r-l+1] % MOD[k] + MOD[k]) % MOD[k];
}

bool check(int size)
{
    for(int i = 1;i <= n-size+1;i++) {

        bool ok = 1;
        for(int j = 0;j < ms;j++) {
            if(getHash(i,i+size-1,j,hashA) != getHash(n-size-i+2,n-i+1,j,hashB) )
                ok = 0;
        }

        if(ok) return 1;
    }
    

    return 0;
}

void solve()
{
    B = A;
    A = ' ' + A;

    for(int j = 0;j < ms;j++) {
        Pow[j][0] = 1;

        for(int i = 1;i <= n;i++)
            Pow[j][i] = (Pow[j][i-1] * base) % MOD[j];

    }

    reverse(B.begin(),B.end());
    B = ' ' + B;

    for(int j = 0;j < ms;j++) 

        for(int i = 1;i <= n;i++) {
            hashA[j][i] = (hashA[j][i-1] * base + A[i] - '0' + 1) % MOD[j];
            hashB[j][i] = (hashB[j][i-1] * base + B[i] - '0' + 1) % MOD[j];
        }

    int L = 1,R = n,ans = 1;
    while(L <= R) {
        int mid = (L+R)/2;
        if(check(mid+1)) {
            ans = mid+1;
            L = mid + 1;
            continue;
        }
        if(check(mid)) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;


    }
    cout << ans;

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> A;
    solve();
    return 0;
}