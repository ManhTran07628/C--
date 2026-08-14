#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
const int base = 256;
ll HashS[MM][2],Pow[MM][2],HashT[MM][2];
int n,ans[MM];
string s,t;

ll getHash(int l,int r,int type,ll Hash[][2])
{
    return (Hash[r][type] - Hash[l - 1][type] * 
        Pow[r - l + 1][type] % MOD[type] + MOD[type]) % MOD[type]; 
}

ll getkey(int l,int r,ll Hash[][2])
{
    ll h1 = getHash(l,r,0,Hash), h2 = getHash(l,r,1,Hash);
    ll key = (h1 << 32) | h2;
    return key;
}

bool check(int x,int y,int len)
{
    int L1 = x - len + 1;
    int R1 = y + len - 1;

    int R2 = n - (L1 - 1);
    int L2 = R2 - (R1 - L1);
    // cout << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << '\n';
    if(L1 < 1 || R1 > n || L2 < 1 || R2 > n) return 0;

    if(getkey(L1,R1,HashS) == getkey(L2,R2,HashT)) return 1;
    return 0;
}

ll bins(int x,int y)
{
    int L = 0,R = n,res = 1;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(x,y,mid)) {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return y + res - 1 - (x - res + 1) + 1;
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
    t = s; reverse(t.begin(),t.end());
    s = ' ' + s;
    t = ' ' + t;
    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i <= n;i++) {
        Pow[i][0] = (Pow[i-1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i-1][1] * base) % MOD[1];
    }

    for(int i = 1;i <= n;i++) {
        HashS[i][0] = (HashS[i-1][0] * base + s[i] - '0' + 1) % MOD[0];
        HashS[i][1] = (HashS[i-1][1] * base + s[i] - '0' + 1) % MOD[1];
        HashT[i][0] = (HashT[i-1][0] * base + t[i] - '0' + 1) % MOD[0];
        HashT[i][1] = (HashT[i-1][1] * base + t[i] - '0' + 1) % MOD[1];
    }

    // bins(3,4);
    // cout << check(1,3,1);
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        cout << bins(i,i) << ' ';
        if(i < n && s[i] == s[i+1]) cout << bins(i,i+1) << ' ';
        else if(i < n && s[i] != s[i+1]) cout << 0 << ' ';
        // res = max(res,bins(i,i));
        // if(i < n && s[i] == s[i + 1])
        //     res = max(res,bins(i,i+1));
    }
    // cout << res;
    return 0;
}