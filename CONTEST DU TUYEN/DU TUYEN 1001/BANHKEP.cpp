#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5;
const int LOG = 31;
const int MOD = 1e9 + 7;
int n, k, a[MM + 7];
pii qr[MM + 7];

vector<vector<ll>> dp;

struct Node
{
    Node *child[2];
    ll res = 0;
    Node() {child[0] = child[1] = nullptr;}
};

Node *root[MM + 7];

void createNode() {
    // root = new Node();
    for(int i = 0;i <= MM;i++)
        root[i] = new Node();
}

void add_nums(Node *p,ll nums,ll val)
{
    if(!p) p = new Node();
    for(int i = LOG;i >= 0;i--) {
        int bit = nums >> i & 1;
        if(p -> child[bit] == nullptr) p -> child[bit] = new Node();
        p = p -> child[bit];
        p -> res += val; p -> res %= MOD;
    }
}

ll getquery(Node *p,ll x,ll L)
{
    if(L < 0) return 0;
    ll res = 0;
    for(int i = LOG;i >= 0;i--) {
        if(!p) break;
        int bitL = L >> i & 1;
        int bitx = x >> i & 1;
        if(bitL == 1) {
            if(p -> child[bitx] != nullptr) {
                res += p -> child[bitx] -> res;
                res %= MOD;
            }
            p = p -> child[bitx ^ 1];
        }
        else p = p -> child[bitx];
    }
    if(p != nullptr) res = (res + p -> res) % MOD;
    return res;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    createNode();
    dp.resize(n + 2);
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) {
        cin >> qr[i].fi >> qr[i].se;
        dp[i].resize(k + 2);
    }
    add_nums(root[0],0,1);
    ll prefix = 0;
    for(int i = 1;i <= n;i++) {
        prefix ^= a[i];
        for(int j = 1;j <= min(i,k);j++) {
            ll cur_res = getquery(root[j-1],prefix,qr[j].se) - getquery(root[j-1],prefix,qr[j].fi - 1);
            dp[i][j] = cur_res; dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
        }
        for(int j = 1;j <= min(i,k);j++)
            add_nums(root[j],prefix,dp[i][j]);
    }
    cout << dp[n][k];
    return 0;
}