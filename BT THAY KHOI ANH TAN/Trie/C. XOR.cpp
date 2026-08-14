#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int LOG = 30;
int n,m;
ll a[MM];

struct Node
{
    Node *child[2];
    int exist = 0;
    Node() {child[0] = child[1] = NULL;}
};

Node *root;

void createNode() {root = new Node();}

void add_nums(ll s)
{
    Node *p = root;
    for(int i = LOG;i >= 0;i--) {
        int bit = (s >> i) & 1;
        if(p -> child[bit] == NULL) p -> child[bit] = new Node();
        p = p -> child[bit];
    }
    p -> exist = s;
}

ll find_max_xor(ll x)
{
    Node *p = root;
    for(int i = LOG;i >= 0;i--) {
        int bit = (x >> i) & 1;
        if(bit == 1) {
            if(p -> child[0] != NULL) p = p -> child[0];
            else p = p -> child[1];
        }
        else {
            if(p -> child[1] != NULL) p = p -> child[1];
            else p = p -> child[0];
        }
    }

    return p -> exist;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        add_nums(a[i]);
    }
    cin >> m;
    while(m--) {
        ll x;
        cin >> x;
        cout << find_max_xor(x) << ' ';
    }
    return 0;
}