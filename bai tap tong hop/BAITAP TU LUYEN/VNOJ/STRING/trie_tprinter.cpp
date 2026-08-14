#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,st = 0;
string ans;

struct Node
{
    Node *child[26];
    int cnt = 0,exist = 0,depth = 0;
    Node(void) {for(int i = 0;i < 26;i++) child[i] = NULL;}
};

Node *root;

void createnode(void) {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    for(auto c:s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();

        p -> child[c - 'a'] -> depth = p -> depth + 1;
        p = p -> child[c - 'a'];
    }
    p -> exist++;
}

void pre_dfs(Node *p)
{
    for(int i = 0;i < 26;i++) {
        if(p -> child[i] == NULL) continue;
        pre_dfs(p -> child[i]);
        p -> depth = max(p -> depth,p -> child[i] -> depth);
    }
}

void dfs(Node *p)
{
    for(int i = 1;i <= (int) p -> exist;i++) ans += 'P';

    vector<pair<int,int>> prio;
    for(int i = 0;i < 26;i++) {
        if(p -> child[i] == NULL) continue;
        prio.push_back({p -> child[i] -> depth,i});
    }
    sort(prio.begin(),prio.end());
    for(auto c:prio) {
        // if(prio.size() == 2) cout << char('a' + c.se) << ' ' << c.fi << '\n';
        ans += char('a' + c.se);
        dfs(p -> child[c.se]);
        ans += '-';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createnode();
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        add_string(s);
    }
    pre_dfs(root);
    dfs(root);
    while(ans[ ans.size()-1 ] == '-') ans.pop_back();
    cout << ans.size() << '\n' << ans;
    return 0;
}