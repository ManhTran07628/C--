#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int MOD = 1e9 + 2277;
const int base = 256;
string T,P;
ll hashT[MM],hashP = 0,Pow[MM],ps[MM];
int k;

ll getHash(int l,int r)
{
    return (hashT[r] - hashT[l-1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getline(cin,T);
    // cin.ignore();
    cin >> P >> k;
    // cin >> T >> P >> k;
    int n = T.size(), m = P.size();
    T = ' ' + T; P = ' ' + P;

    Pow[0] = 1;
    for(int i = 1;i <= n;i++) {
        Pow[i] = (Pow[i-1] * base) % MOD;
    }

    for(int i = 1;i <= n;i++)
        hashT[i] = (hashT[i-1] * base + T[i] - '0' + 1) % MOD;
    
    for(int i = 1;i <= m;i++)
        hashP = (hashP * base + P[i] - '0' + 1) % MOD;

    int res = 0;
    
    for(int i = m;i <= n;i++) { // mang hieu thang cuoi cung thoa man
        if(getHash(i - m + 1,i) == hashP) {
            int l = i;
            int r = min(n,i - m + k);
            ps[l]++;
            ps[r + 1]--;
            // cout << l << ' ' << r << '\n';
        }
    }

    for(int i = 1;i <= n;i++) {
        ps[i] += ps[i-1];
        if(ps[i] && i >= k) res++;
    }
    cout << res;
    return 0;
}