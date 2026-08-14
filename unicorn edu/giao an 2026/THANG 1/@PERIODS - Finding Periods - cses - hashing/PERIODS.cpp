#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int base = 256;
const int MOD = 1e9 + 2277;
int Hash[MM],Pow[MM];
string s;
map<int,int> st;
 
ll getHash(int l,int r)
{
    return (1ll * Hash[r] - 1ll * Hash[l-1] * 1ll * Pow[r - l + 1] % MOD + MOD) % MOD;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    Pow[0] = 1;
    for(int i = 1;i < MM;i++) Pow[i] = (1ll * Pow[i-1] * base) % MOD;
    for(int i = 1;i <= n;i++)
        Hash[i] = (1ll * Hash[i-1] * base + s[i] - '0' + 1) % MOD;
    
 
    for(int i = 1;i < n;i++) {
 
 
        int len = i, j = i,ok = 1;
 
        while(j < n) {
            if(j + len <= n) {
                if(getHash(1,len) != getHash(j + 1,j + len)) {
                    ok = 0; break;
                }
            }
            else {
                int nxt = j + 1;
                int sz = n - nxt + 1;
                if(getHash(1,sz) != getHash(nxt,nxt + sz - 1)) {
                    ok = 0; break;
                }
            }
            j += i;
        }
        if(ok) cout << i << ' ';
    }
    cout << n;
    return 0;
}