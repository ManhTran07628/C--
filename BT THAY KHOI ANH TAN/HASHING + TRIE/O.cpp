#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
int n,q;

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
    for(auto c:s) {
        if(p -> child[c - 'a'] == nullptr) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
    }
    p -> exist++;
}

bool query(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - 'a'] == nullptr) return 0;
        p = p -> child[c - 'a'];
    }
    return p -> exist > 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        add_string(s);
    }
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        cout << ( query(s) ? "YES" : "NO" ) << '\n';
    }
    return 0;
}