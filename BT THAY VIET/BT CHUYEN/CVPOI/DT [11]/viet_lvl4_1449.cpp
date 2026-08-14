#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MOD = 1e8 - 3;
const int MM = 2e5 + 7;
int n,pos[MM];
pii a[MM + 7],b[MM + 7];

int bit[MM + 7];

void update(int x,int val)
{
    for(;x <= MM;x += (x & -x)) bit[x] += val;
}

int get(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

int qr(int l,int r)
{
    return get(r) - get(l - 1);
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i = 1;i <= n;i++) {
        pos[a[i].se] = b[i].se;
    }
    int res = 0;
    for(int i = 1;i <= n;i++) {
        // cout << a[i].se << ' ' << b[i].se << '\n';
        res += qr(pos[i] + 1,MM); res %= MOD;
        update(pos[i],1);
    }
    cout << res % MOD;
    return 0;
}

// 1 3 4 2
// 1 4 2 3