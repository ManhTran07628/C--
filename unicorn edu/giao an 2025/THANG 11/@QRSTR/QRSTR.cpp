#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
const int MOD = 1e9 + 2277;
const int base = 256;
int n,m,q;
ll hashA[MM],hashB[MM],Pow[MM];
string A,B;

ll getHash(int l,int r,ll Hash[])
{
    return (Hash[r] - Hash[l - 1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}

bool check(int l,int u,int len)
{
    return getHash(l,l + len - 1,hashA) == getHash(u,u + len - 1,hashB);
}

char solve(int l,int r,int u,int v)
{
    // if(r - l + 1 < v - u + 1) return '<';
    // else if(r - l + 1 > v - u + 1) return '>';
    int szA = r - l + 1, szB = v - u + 1;

    int L = 0,R = min(szA,szB), res = 0;
    while(L <= R) {
        int mid = (L+R)/2;
        if(check(l,u,mid)) {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    if(l + res - 1 == r && u + res - 1 == v) return '=';
    if(l + res - 1 == r && u + res - 1 < v) return '<';
    if(l + res - 1 < r && u + res - 1 == v) return '>';
 
    if(l + res - 1 == r) return '=';
    else {
        if(A[l + res] > B[u + res]) return '>';
        return '<';
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> A >> B;
    A = ' ' + A;
    B = ' ' + B;

    // build Hash
    Pow[0] = 1;
    for(int i = 1;i <= n;i++) {
        Pow[i] = (Pow[i-1] * base) % MOD;
    }
    for(int i = 1;i <= n;i++) 
        hashA[i] = (hashA[i-1] * base + A[i] - '0' + 1) % MOD;

    for(int i = 1;i <= m;i++) 
        hashB[i] = (hashB[i-1] * base + B[i] - '0' + 1) % MOD;

    // query
    cin >> q;
    while(q--) {
        int l,r,u,v;
        cin >> l >> r >> u >> v;
        cout << solve(l,r,u,v);
    }
    return 0;
}   