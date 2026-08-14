#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int base = 256;
const int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
ll Hash[MM][2],Pow[MM][2];
int n;
string s; 

ll getHash(int L,int R,int type)
{
    return (Hash[R][type] - Hash[L - 1][type] * Pow[R - L + 1][type] % MOD[type] + MOD[type]) % MOD[type];
}

// 0 -> xau cu be hon   1 -> xau moi be hon
int bins(int L_max,int R_max,int cur_L,int cur_R) 
{
    int L = 0, R = n - 1, res = -1;
    while(L <= R) {
        int mid = (L + R) / 2;
        bool ok = (getHash(L_max,L_max + mid,0) == getHash(cur_L,cur_L + mid,0)) && 
                (getHash(L_max,L_max + mid,1) == getHash(cur_L,cur_L + mid,1));
        if(ok) {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    if(L_max + res == R_max) return 0;
    if(res == -1) {
        if(s[L_max] > s[cur_L]) return 1;
        return 0;
    }
    if(s[L_max + res + 1] > s[cur_L + res + 1]) return 1;
    return 0;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> s;
    n = s.size();
    s = s + s;
    s = ' ' + s;
    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i < MM;i++) {
        Pow[i][0] = (Pow[i-1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i-1][1] * base) % MOD[1];
    }

    for(int i = 1;i <= n + n;i++) {
        Hash[i][0] = (Hash[i-1][0] * base + s[i] - '0' + 1) % MOD[0];
        Hash[i][1] = (Hash[i-1][1] * base + s[i] - '0' + 1) % MOD[1];
    }
    int L_max = 1,R_max = n;
    for(int i = 2;i + n - 1 <= n + n;i++) {
        int cur_L = i, cur_R = i + n - 1;
        if(bins(L_max,R_max,cur_L,cur_R) == 1) {
            L_max = cur_L, R_max = cur_R;
        }
    }
    for(int i = L_max;i <= R_max;i++) cout << s[i]; 
    return 0;
}