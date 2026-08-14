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
    Node *child[26];
    int mask = 0,cnt = 0,exist = 0;
    Node() {for(int i = 0;i < 26;i++) child[i] = nullptr;}
};

Node *root;

void createnode() {root = new Node();}

void add_string(string s,int type)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - 'a'] == nullptr) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
        p -> mask |= (1 << type);
        p -> child++;
    }
    p -> exist++;
}

bool dfs(Node *p,int depth)
{
    for(int i = 0;i < 26;i++) {
        if(depth % 2 == 0) {
            if(p -> child[i] == 0)
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        add_string(s,0);
    }
    for(int i = 1;i <= m;i++) {
        string s;
        cin >> s;
        add_string(s,1);
    }
    
    return 0;
}