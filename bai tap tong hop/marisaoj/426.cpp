#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n;

struct Node
{
    Node *child[26][26];
    int cnt = 0;
    Node() {
        for(int i = 0;i < 26;i++) 
            for(int j = 0;j < 26;j++) 
                child[i][j] = NULL;
    }
};

Node *root;

void createNode(void) {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(int i = 0;i < s.size();i++) {
        int x = s[i] - 'a',y = s[s.size() - i - 1] - 'a';
        if(p -> child[x][y] == NULL) p -> child[x][y] = new Node();
        p = p -> child[x][y];
        p -> cnt++;
    }
}

ll dfs(Node *p,int h)
{
    ll res = 0;
    if(p != root) {
        res += (p -> cnt / 2) * (h * h - (h - 1) * (h - 1));
    }
    for(int i = 0;i < 26;i++) {
        for(int j = 0;j < 26;j++) {
            if(p -> child[i][j] != NULL)
                res += dfs(p -> child[i][j],h + 1);
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        add_string(s);
    }
    cout << dfs(root,0);
    return 0;
}