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
    int exist = 0,cnt = 0;
    
    Node() {for(int i = 0;i < 26;i++) child[i] = NULL;}
};

Node *root;

void createNode(void) {root = new Node();}

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

bool find_prefix(Node *p)
{
    if(p -> exist >= 1 && p -> cnt >= 2) return 1;

    for(int i = 0;i < 26;i++) {
        if(p -> child[i] != NULL) {
            if(find_prefix(p -> child[i])) return 1;
        }
    }

    return 0;
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
    cout << (find_prefix(root) ? "YES" : "NO");
    return 0;
}