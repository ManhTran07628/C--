#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
const int base = 256;
ll hashS[MM][2],hashP[MM][2];
ll Pow[MM][2];
int numS,numP;

ll gethash(int l,int r,int type,ll Hash[][2])
{
    return (Hash[r][type] - Hash[l - 1][type] * Pow[r - l + 1][type] % MOD[type] + MOD[type]) 
    % MOD[type];
}

ll getkey(int l,int r,ll Hash[][2])
{
    ll h1 = gethash(l,r,0,Hash);
    ll h2 = gethash(l,r,0,Hash);
    ll key = (h1 << 32) | h2;
    return key;
}

string s,p;

bool check(int old_l,int old_r)
{
    int L = old_l, R = old_r, res = -1;
    while(L <= R) {
        int mid = (L + R) / 2;
        int len = mid - old_l + 1;
        if(getkey(old_l,mid,hashS) == getkey(1,len,hashP)) {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }

    // res++;
    
    if(res == -1) res = old_l + 1;
    else res += 2;
    // cout << old_l << ' ' << old_r << ' ' << res << '\n';
    if(res > old_r) return 1;

    int nxt_old_l = old_l;

    old_l = res;
    L = res, R = old_r;
    res = -1;

    // cout << old_l - nxt_old_l + 1 << '\n';

    while(L <= R) {
        int mid = (L + R) / 2;
        int len = mid - old_l + 1, lenp = old_l - nxt_old_l + 1;
        if(getkey(old_l,mid,hashS) == getkey(lenp,len + lenp - 1,hashP)) {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }

    // cout << old_l << ' ' << old_r << ' ' << res << '\n';

    return res == old_r;
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
    cin >> s >> p;
    numS = s.size(); numP = p.size();
    s = ' ' + s;
    p = ' ' + p;
    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i < MM;i++) {
        Pow[i][0] = (Pow[i - 1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i - 1][1] * base) % MOD[1];
    }

    for(int i = 1;i <= numS;i++) {
        hashS[i][0] = (hashS[i - 1][0] * base + s[i] - '0' + 1) % MOD[0];
        hashS[i][1] = (hashS[i - 1][1] * base + s[i] - '0' + 1) % MOD[1];
    }

    for(int i = 1;i <= numP;i++) {
        hashP[i][0] = (hashP[i - 1][0] * base + p[i] - '0' + 1) % MOD[0];
        hashP[i][1] = (hashP[i - 1][1] * base + p[i] - '0' + 1) % MOD[1];
    }

    int res = 0;
    for(int l = 1;l + numP - 1 <= numS;l++) {
        int r = l + numP - 1;
        if(getkey(l,r,hashS) == getkey(1,numP,hashP)) {
            res++;
            continue;
        }
        res += check(l,r);
        // cout << l << ' ' << r << ' ' << check(l,r) << '\n';
    }
    

    // cout << check(1,4);
    cout << res;
    return 0;
}