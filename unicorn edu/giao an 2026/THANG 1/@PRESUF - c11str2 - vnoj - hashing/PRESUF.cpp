#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int MOD = 1e9 + 2277;
const int base = 256;
ll Pow[MM],hashA[MM],hashB[MM];
string A,B;

ll getHash(int l,int r,ll Hash[])
{
    return (Hash[r] - Hash[l-1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    int n = A.size(), m = B.size();
    A = ' ' + A; B = ' ' + B;
    Pow[0] = 1;
    for(int i = 1;i < MM;i++)
        Pow[i] = (Pow[i-1] * base) % MOD;
    for(int i = 1;i <= n;i++)
        hashA[i] = (hashA[i-1] * base + A[i] - '0' + 1) % MOD;
    for(int i = 1;i <= m;i++)
        hashB[i] = (hashB[i-1] * base + B[i] - '0' + 1) % MOD;

    string s = A;
    for(int i = 1;i <= n;i++) {
        int len = min(i + min(n,m) - 1,n - i + 1);
        // cout << i << ' ' << len << '\n';
        int l1 = i; 
        int r1 = i + len - 1;
        int l2 = 1;
        int r2 = l2 + len - 1;
        if(getHash(l1,r1,hashA) == getHash(l2,r2,hashB)) {
            for(int j = 1;j <= n;j++) cout << A[j];
            for(int j = r2+1;j <= m;j++) cout << B[j];
            return 0;
        }
        // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' <<
        //  getHash(l1,r1,hashA) << ' ' << getHash(l2,r2,hashB) << '\n';
    }
    for(int j = 1;j <= n;j++) cout << A[j];
    for(int j = 1;j <= m;j++) cout << B[j];
    return 0;
}
