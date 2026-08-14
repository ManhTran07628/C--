#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int m,n;


struct Node
{
    Node *child[26];
    int cnt;
    Node() {
        for(int i = 0;i < 26;i++) child[i] = NULL;
        cnt = 0;
    }
};

Node *root;

void createNode() {
    root = new Node();
}

void add_string(string s)
{
    Node *p = root;
    for(auto f:s) {
        int c = f - 'a';
        if(p -> child[c] == NULL) p -> child[c] = new Node();

        p = p -> child[c];
        p -> cnt++;
        // cout << c << ' ' << p ->cnt << '\n';
    }

}

int find_nums(string s)
{
    Node *p = root;
    for(auto f:s) {
        int c = f - 'a';
        if(p -> child[c] != NULL) p = p -> child[c];
        else return 0;
        // else return p -> cnt;
    }
    return p -> cnt;
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
    cin >> m;
    while(m--) {
        string a;
        cin >> a;
        cout << find_nums(a) << '\n';
    }


    return 0;
}