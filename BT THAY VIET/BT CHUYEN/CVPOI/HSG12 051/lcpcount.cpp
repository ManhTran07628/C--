#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
const int base = 256;
int n,m,max_sz = 0;
ll res = 0;
unordered_map<ll,ll> mp;

struct Node
{
    Node *child[26];
    int cnt = 0, exist = 0;
    Node() {
        for(int i = 0;i < 26;i++)
            child[i] = nullptr;
    }
};

Node *root;

void makeNode() {root = new Node();}

void add_str(string a)
{
    Node *p = root;
    for(auto c:a) {
        if(p -> child[c - 'a'] == nullptr) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
        p -> cnt++;
    }
}

void dfs(Node *p,ll hash1,ll hash2,int cur_sz)
{
    if(cur_sz > max_sz) return;
    if(!p) return;
    ll key = (1ll * hash1 << 32) | hash2;
    ll cnt = p -> cnt, st = 0;
    for(int i = 0;i < 26;i++) {
        if(p -> child[i] == nullptr) continue;
        ll new_h1 = (hash1 * base + i + 1) % MOD[0];
        ll new_h2 = (hash2 * base + i + 1) % MOD[1];
        char c = i + 'a';
        if(p -> child[i] -> cnt >= 2) dfs(p -> child[i],new_h1,new_h2,cur_sz + 1);
        ll C = p -> child[i] -> cnt;
        st += C * (C - 1) / 2;
    }

    if(mp[key]) {
        res += cnt * (cnt - 1) / 2 - st;
    }
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
    makeNode();
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;
        add_str(s);
    }

    for(int i = 1;i <= m;i++) {
        string s; cin >> s;
        int sz = s.size();
        max_sz = max(max_sz,sz);
        s = ' ' + s;
        ll Hash1 = 0,Hash2 = 0;
        for(int j = 1;j <= sz;j++) {
            Hash1 = (Hash1 * base + s[j] - 'a' + 1) % MOD[0];
            Hash2 = (Hash2 * base + s[j] - 'a' + 1) % MOD[1];
        }

        ll key = (1ll * Hash1 << 32) | Hash2;
        mp[key] = 1;
    }

    dfs(root,0,0,0);
    cout << res;

    return 0;
}
