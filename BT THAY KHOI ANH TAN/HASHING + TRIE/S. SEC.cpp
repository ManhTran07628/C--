#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int m,n;

struct Node
{
    Node *child[2];
    int exist = 0,cnt = 0;
    Node() {for(int i = 0;i < 2;i++) child[i] = nullptr;}
};

Node *root;

void createNode() {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - '0'] == nullptr) p -> child[c - '0'] = new Node();
        p = p -> child[c - '0'];
        p -> cnt++;
    }
    p -> exist++;
}

int query(string s)
{
    Node *p = root;
    int res = 0;
    for(auto c: s) {
        if(p -> child[c - '0'] == nullptr) return res;
        p = p -> child[c - '0'];
        res += p -> exist;
    }
    res += (p -> cnt - p -> exist);
    return res;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        int sz; cin >> sz;
        string s;
        for(int j = 1;j <= sz;j++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        add_string(s);
    }

    for(int i = 1;i <= n;i++) {
        int sz; cin >> sz;
        string s;
        for(int j = 1;j <= sz;j++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        cout << query(s) << '\n';
    }

    return 0;
}