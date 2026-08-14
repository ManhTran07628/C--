#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,ans = 0;


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

void createNode()
{
    root = new Node();
}

void add_string(string &s)
{
    Node *p = root;
    for(auto c :s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
    }
    p -> exist = 1;
}

void find_string(Node *p,int cur_ans)
{
    ans = max(ans,cur_ans + 1);
    for(int i = 0;i < 26;i++) {
        
        if(p -> child[i] != NULL) {
            find_string(p -> child[i],cur_ans + (p -> exist));
        }
        
    }
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
    find_string(root,0);
    cout << ans;
    return 0;
}