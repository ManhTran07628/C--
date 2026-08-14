#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 3e5+7;
const int MOD = 1337377;
string s;
int n,dp[MM];

struct Node
{
    Node *child[26];
    int exist = 0;
    Node() {for(int i = 0;i < 26;i++) child[i] = nullptr;}
};

Node *root;

void createNode() {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(auto c: s) {
        if(p -> child[c - 'a'] == nullptr) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
    }
    p -> exist++;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> s >> n;  
    for(int i = 1;i <= n;i++) {
        string t;
        cin >> t;
        add_string(t);
    }
    
    // dp
    int sz = s.size();
    s = ' ' + s;
    dp[0] = 1;
    for(int i = 1;i <= sz;i++) {
        Node *p = root;
        for(int j = i;j <= sz;j++) {
            
            if(p -> child[ s[j] - 'a' ] == nullptr) break;
            p = p -> child[ s[j] - 'a' ];
    
            if(p -> exist > 0) {
                dp[j] = (dp[j] + dp[i-1]) % MOD;
            }

        }
    }
    cout << dp[sz];
    return 0;
}