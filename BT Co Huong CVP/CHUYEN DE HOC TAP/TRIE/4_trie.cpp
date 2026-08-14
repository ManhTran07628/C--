#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int MOD = 1000000007;
int n,dp[MM];
string s;


struct Trie
{
    struct Node
    {
        Node *child[26];
        int exist;

        Node() {
            for(int i = 0;i < 26;i++) child[i] = NULL;
            exist = 0;
        }
    };

    Node *root;

    Trie() {
        root = new Node();
    }

    void add_string(string s)
    {
        Node *p = root;
        for(auto c:s) {
            if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();
            p = p -> child[c - 'a'];
        }
        p -> exist++;
    }

    pair<int,int> find_string(string s)
    {
        Node *p = root;
        for(auto c:s) {
            if(p -> child[c - 'a'] == NULL) return {0,0};
            p = p -> child[c - 'a'];
        }
        return {(int) p -> exist,1};
    }
};



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Trie trie;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s;
        trie.add_string(s);
    }
    cin >> s;
    int m = s.size();
    s = ' ' + s;
    dp[0] = 1;
    for(int i = 1;i <= m;i++) {
        string t;
        for(int j = i;j <= m;j++) {
            t += s[j];
            auto pp = trie.find_string(t);
            if(!pp.se) break;
            
            if(pp.fi) dp[j] = (1ll * dp[j] + dp[i-1]) % MOD;
 
        }
    }
    cout << dp[m];
    return 0;
}