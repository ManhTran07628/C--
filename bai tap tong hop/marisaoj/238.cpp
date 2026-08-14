#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int q;
vector<string> qr;

map<int,multiset<int>> lt;
// tap hop so lan di qua cua 1 node tren cay trie co do cao la h
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
    int h = 0;
    for(auto c:s) {
        if(p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Node();
        p = p -> child[c - 'a'];
        ++h;

        auto it = lt[h].find(p -> cnt);
        if(it != lt[h].end()) lt[h].erase(it);

        p -> cnt++;
        lt[h].insert(p -> cnt);
    }
}

void del_string(string s)
{
    Node *p = root;
    int h = 0;
    for(auto c:s) {

        p = p -> child[c - 'a'];
        ++h;

        auto it = lt[h].find(p -> cnt);
        if(it != lt[h].end()) lt[h].erase(it);
        
        p -> cnt--;
        lt[h].insert(p -> cnt);
    }
}

bool query(int k,int l)
{
    if(lt[l].empty()) return 0;
    auto it = lt[l].rbegin();
    return *it >= k;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> q;
    int id = 0;
    while(q--) {
        int type,k,l;
        string s;
        cin >> type;
        if(type == 1) {
            cin >> s;
            reverse(s.begin(),s.end());
            qr.push_back(s);
            add_string(s);
        }
        if(type == 2) {
            cin >> k >> l;
            cout << (query(k,l) ? "YES" : "NO") << '\n';
            qr.push_back("0");
        }
        else if(type == 3) {
            cin >> k;
            del_string(qr[k-1]);
            qr.push_back("0");
        }
    }
    return 0;
}