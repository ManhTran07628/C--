#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int m;

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

int dfs(Node *p)
{
    int cur = p -> exist;
    for(int i = 0;i < 26;i++) {
        if(p -> child[i] == nullptr) continue;

        cur = max(cur,p -> exist + dfs(p -> child[i]));
    }
    return cur;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> m;
    for(int i = 1;i <= m;i++) {
        string s;
        cin >> s;
        add_string(s);
    }
    cout << dfs(root);
    return 0;
}