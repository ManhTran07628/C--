#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
const int MOD = 1337377;
string s,t;
ll dp[MM],n;

struct Node
{
    Node *child[26];
    int exist;

    Node()
    {
        for(int i = 0;i < 26;i++) child[i] = NULL;
        exist = 0;
    }
};

Node *root;

void createNode() {root = new Node();}

void add_string(string &s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
    }
    p -> exist = 1;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> s >> n;
    for(int i = 1;i <= n;i++) {
        cin >> t;
        add_string(t);
    }
    dp[0] = 1;
    int m = s.size();
    s = ' ' + s;
    for(int i = 1;i <= m;i++) {
        Node *p = root;
        for(int j = i;j <= m;j++) {

            if(p -> child[ s[j] - 'a' ] == NULL) break;
            p = p -> child[ s[j] - 'a' ];

            if(p -> exist == 1) 
                dp[j] = (dp[j] + dp[i-1]) % MOD;

        }

    }

    cout << dp[m];
    return 0;
}