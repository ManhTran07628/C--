#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int n;
string s[MM];
ll res = 0;

struct Node
{
    Node *child[26];
    int cnt = 0;
    Node() {for(int i = 0;i < 26;i++) child[i] = NULL;}
};

Node *root;

void createNode() {root = new Node();}

void add_string(string s)
{
    Node *p = root;
    ll high = 1;
    p -> cnt++;
    for(auto c:s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();

        p -> child[c - 'a'] -> cnt++;

        res += (p -> cnt - p -> child[c - 'a'] -> cnt) * high;

        p = p -> child[c - 'a'];

        high++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s[i];
    }
    sort(s+1,s+n+1,[] (string &x,string &y){
        return x.size() > y.size();
    });
    for(int i = 1;i <= n;i++) {
        add_string(s[i]);
    }
    cout << res;
    return 0;   
}