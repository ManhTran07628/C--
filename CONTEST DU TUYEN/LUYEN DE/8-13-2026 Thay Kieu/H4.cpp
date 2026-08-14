#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
string s;
int n;
ll T,K;

namespace subtask1
{
    struct Node
    {
        Node *child[26];
        int cnt = 0, exist = 0;
        Node() {for(int i = 0;i < 26;i++) child[i] = nullptr;};
    };

    string ans = "";

    Node *root;

    void createNode() {root = new Node();}

    void add_string(string s)
    {
        Node *p = root;
        for(auto c:s) {
            if(p -> child[c - 'a'] == nullptr) p -> child[c - 'a'] = new Node();
            p = p -> child[c - 'a'];
            p -> cnt++;
        }
        p -> exist++;
    }

    bool dfs(Node *p,string res)
    {
        K -= p -> exist;
        // cout << res << ' ' << K << '\n';
        if(K <= 0) {
            ans = res;
            return 1;
        }
        for(char i = 'a';i <= 'z';i++) {
            if(p -> child[i - 'a'] == nullptr) continue;
            if(dfs(p -> child[i - 'a'],res + i)) return 1;
        }
        return 0;
    }

    int base = 256;
    int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
    ll Hash[MM][2] = {}, Pow[MM][2] = {};

    ll getHash(int L,int R,int t)
    {
        return (Hash[R][t] - Hash[L - 1][t] * Pow[R - L + 1][t] % MOD[t] + MOD[t]) % MOD[t];
    }

    ll getkey(int L,int R)
    {
        ll h1 = getHash(L,R,0), h2 = getHash(L,R,1);
        ll key = (h1 << 32) | h2;
        return key;
    }

    map<ll,int> mp;
    unordered_map<ll,string> str;

    void solve()
    {
        createNode();
        Pow[0][0] = Pow[0][1] = 1;
        for(int i = 1;i <= n;i++) {
            Pow[i][0] = (Pow[i - 1][0] * base) % MOD[0];
            Pow[i][1] = (Pow[i - 1][1] * base) % MOD[1];

            Hash[i][0] = (Hash[i - 1][0] * base + s[i] - '0' + 1) % MOD[0];
            Hash[i][1] = (Hash[i - 1][1] * base + s[i] - '0' + 1) % MOD[1];
        }

        for(int l = 1;l <= n;l++) {
            string f = "";
            for(int r = l;r <= n;r++) {
                f.push_back(s[r]);
                mp[ getkey(l,r) ]++;
                if(str.find(getkey(l,r)) == str.end()) {
                    str[ getkey(l,r) ] = f;
                }
            }
        }

        for(auto m:mp) {
            if(m.se < T) continue;
            
            add_string( str[m.fi] );
        }

        if(dfs(root,"")) {
            cout << ans;
        }
        else cout << -1;
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
    cin >> s >> T >> K;
    n = s.size();
    s = ' ' + s;
    subtask1::solve();
    return 0;
}