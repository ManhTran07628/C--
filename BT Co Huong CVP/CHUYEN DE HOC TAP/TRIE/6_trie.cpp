#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e4+7;
int n,m;

struct Trie
{ 
    struct Node{
        Node *child[26];
        int exist;
    
        Node() {
            for(int i = 0;i < 26;i++) child[i] = NULL;
            exist = 0;
        }
    };
    
    Node *root;
    Trie() {
        root = new Node();
    };

    void add_string(string s) {
        Node *p = root;
        for(auto f : s) {
            int c = f - 'a';
            if(p->child[c] == NULL) p->child[c] = new Node();

            p = p->child[c];
        }
        p->exist++;
    }

    bool find_string(string s) {
        Node *p = root;
        for(auto f:s) {
            int c = f - 'a';
            if(p -> child[c] == NULL) return 0;
            p = p -> child[c];
        }
        return (p -> exist >= 1); 
    }
    
};


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    Trie t;
    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        t.add_string(s);
    }
    cin >> m;
    while(m--) {
        string s;
        cin >> s;
        cout << t.find_string(s) << '\n';
    }
    return 0;
}