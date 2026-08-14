#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int MOD = 1e9 + 7;
int n,k,a[MM];
ll prefix[MM];
pair<int,int> Q[MM];
vector<vector<int>> dp;

struct Node
{
    Node *child[2];
    ll cnt = 0;
    Node() {child[0] = child[1] = nullptr;}
};

Node *root[MM];

void createNode(int i) {root[i] = new Node();}

void add_nums(Node *root,int k,ll f)
{
    Node *p = root;
    for(int i = 30;i >= 0;i--) {
        int B = (k >> i) & 1;
        if(p -> child[B] == nullptr) p -> child[B] = new Node();
        p = p -> child[B];
        p -> cnt += f;
        p -> cnt %= MOD;
    }
}
// P xor prefix <= K

ll find_prefix(Node *root,int P,int K)
{
    if(K < 0) return 0;
    Node *p = root;
    ll res = 0;
    for(int i = 30;i >= 0;i--) {
        if(p == nullptr) break;
        int Pi = (P >> i) & 1;
        int Ki = (K >> i) & 1;
        if(Ki == 1) {
            if(p -> child[Pi] != nullptr)
                res = (res + p -> child[Pi] -> cnt) % MOD;

            p = p -> child[Pi ^ 1];
        }
        else p = p -> child[Pi];
    }
    if(p != nullptr) res = (res + p -> cnt) % MOD;
    return res;
}

// dp[i][k] = sigma dp[1 -> i-1][k-1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    dp.resize(n + 7, vector<int> (k + 7));

    for(int i = 0;i <= n;i++) {
        createNode(i);
        // add_nums(root[i],0,0);
    }
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        prefix[i] = prefix[i-1] ^ a[i];
    }

    for(int i = 1;i <= k;i++) {
        cin >> Q[i].fi >> Q[i].se;
    }

    add_nums(root[0],0,1);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= min(i,k);j++) {
            int L = Q[j].fi - 1, R = Q[j].se;

            ll res = find_prefix(root[j-1],prefix[i],R) - find_prefix(root[j-1],prefix[i],L);
            res = (res % MOD + MOD) % MOD;

            dp[i][j] = res;
        }

        for(int j = 1;j <= min(i,k);j++) 
            add_nums(root[j],prefix[i],dp[i][j]);
    }

    cout << dp[n][k];
    return 0;
}