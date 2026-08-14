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
    Node *child[26];
    int cnt = 0,exist = 0;
    Node() {for(int i = 0;i < 26;i++) child[i] = NULL;}
};

Node *root;

void createNode() {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
        p -> cnt++;
    }
    p -> exist++;
}

int dfs(Node *p,int h)
{
    int res = 0;
    if(p -> cnt == 1) return h;
    for(int i = 0;i < 26;i++)
        if(p -> child[i] != NULL)
            res += dfs(p -> child[i],h+1);

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