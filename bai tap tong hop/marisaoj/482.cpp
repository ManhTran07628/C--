#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int n,q;
bool dp[MM];

struct Node
{
    Node *child[26];
    int exist = 0;
    Node(void) {for(int i = 0;i < 26;i++) child[i] = NULL;}
};

Node *root;

void createnode(void) {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
    }
    p -> exist++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createnode();
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        add_string(s);
    }
    while(q--) {
        string s;
        cin >> s;
        int m = s.size();
        s = ' ' + s;
        dp[0] = 1;
        for(int i = 1;i <= m;i++) dp[i] = 0;
        for(int i = 1;i <= m;i++) {
            Node *p = root;
            for(int j = i;j <= min(i+10,m);j++) {
                if(p -> child[ s[j] - 'a' ] == NULL) break;

                p = p -> child[ s[j] - 'a' ];
                

                if(p -> exist >= 1)
                    dp[j] |= dp[i-1];
            }
        }

        cout << (dp[m] ? "YES" : "NO") << '\n';
    }
    return 0;
}