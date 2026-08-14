#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,m;

struct Node
{
    Node *child[2];
    int cnt = 0;
    Node() {child[0] = child[1] = NULL;};
};

Node *root;

void createNode() {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - '0'] == NULL) p -> child[c - '0'] = new Node();
        p = p -> child[c - '0'];
        p -> cnt++;
    }
}

int cnt_prefix(string s)
{
    Node *p = root;
    int cnt = 0;
    for(auto c:s) {
        if(p -> child[c - '0'] != NULL) {
            p = p -> child[c - '0'];
            cnt = max(cnt,p -> cnt);
        }
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        string s;
        int lim;
        cin >> lim;
        while(lim--) {
            char c;
            cin >> c;
            s += c;
        }
        add_string(s);
    }

    for(int i = 1;i <= m;i++) {
        string s;
        int lim;
        cin >> lim;
        while(lim--) {
            char c;
            cin >> c;
            s += c;
        }
        cout << cnt_prefix(s) << '\n';
    }
    return 0;
}