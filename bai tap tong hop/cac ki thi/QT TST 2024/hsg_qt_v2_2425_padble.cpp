#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
const int base = 256;
ll HashS[MM][2],HashrevS[MM][2],Pow[MM][2];
int n;
string s,t;

ll gethash(int l,int r,int ty,ll Hash[][2])
{
    return (Hash[r][ty] - Hash[l - 1][ty] * Pow[r - l + 1][ty] % MOD[ty] + MOD[ty]) % MOD[ty];
}

ll getkey(int l,int r,ll Hash[][2])
{
    ll h1 = gethash(l,r,0,Hash), h2 = gethash(l,r,1,Hash);
    ll key = (h1 << 32) | h2;
    return key;
}

vector<int> vec;

bool check(int len)
{
    for(int i = 1;i + 2 * len - 1 <= n;i++) {
        int sl1 = i; int sr1 = i + len - 1;
        int sl2 = sr1 + 1; int sr2 = sl2 + len - 1;

        int tr2 = n - (sl1 - 1); int tl2 = tr2 - len + 1;
        int tr1 = tl2 - 1; int tl1 = tr1 - len + 1;

        // cout << sl1 << ' ' << sr1 << ' ' << tl2 << ' ' << tr2 << '\n';
        // if(getkey(sl1,sr1,HashS) == getkey(tl2,tr2,HashrevS)) {

        //     cout << sl1 << "_" << sr1 << ": ";
        //     for(int j = sl1;j <= sr1;j++) cout << s[i];
        //     cout << '\n';
        // }

        if(getkey(sl1,sr1,HashS) == getkey(tl2,tr2,HashrevS) &&
            getkey(sl2,sr2,HashS) == getkey(tl1,tr1,HashrevS) && 
            getkey(sl1,sr1,HashS) != getkey(sl2,sr2,HashS)) return 1; 
    }

    return 0;
}

bool checkpalind(int len)
{
    for(int i = 1;i + len - 1 <= n;i++) {
        int sl1 = i; int sr1 = i + len - 1;

        int tr2 = n - (sl1 - 1); int tl2 = tr2 - len + 1;

        if(getkey(sl1,sr1,HashS) == getkey(tl2,tr2,HashrevS)) return 1; 
    }

    return 0;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "PADBLE"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> s; t = s;
    n = s.size();
    s = ' ' + s;
    reverse(t.begin(),t.end()); t = ' ' + t;

    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i <= n;i++)  {
        // cout << s[i];
        Pow[i][0] = (Pow[i - 1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i - 1][1] * base) % MOD[1];

        HashS[i][0] = (HashS[i - 1][0] * base + s[i] - '0' + 1) % MOD[0];
        HashS[i][1] = (HashS[i - 1][1] * base + s[i] - '0' + 1) % MOD[1];

        HashrevS[i][0] = (HashrevS[i - 1][0] * base + t[i] - '0' + 1) % MOD[0];
        HashrevS[i][1] = (HashrevS[i - 1][1] * base + t[i] - '0' + 1) % MOD[1];
    } //cout << '\n';

    // cout << 3 << '\n';

    if(!check(1)) {
        cout << -1;
        return 0;
    }
    
    int L = 1, R = n, len = -1;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(checkpalind(mid)) {
            len = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }

    if(len == -1) {
        cout << len;
        return 0;
    }
    // cout << len << '\n';
    
    for(int i = len;i >= 1;i--) {
        if(check(i)) {
            len = i;
            break;
        }
    }

    if(len == -1) {
        cout << len;
        return 0;
    }

    int cnt = 0;
    for(int i = 1;i + len * 2 - 1 <= n;i++) {
        int sl1 = i; int sr1 = i + len - 1;
        int sl2 = sr1 + 1; int sr2 = sl2 + len - 1;

        int tr2 = n - (sl1 - 1); int tl2 = tr2 - len + 1;
        int tr1 = tl2 - 1; int tl1 = tr1 - len + 1;

        if(getkey(sl1,sr1,HashS) == getkey(tl2,tr2,HashrevS) &&
            getkey(sl2,sr2,HashS) == getkey(tl1,tr1,HashrevS) && 
            getkey(sl1,sr1,HashS) != getkey(sl2,sr2,HashS)) cnt++;
    }

    cout << len * 2 << ' ' << cnt;
    return 0;
}