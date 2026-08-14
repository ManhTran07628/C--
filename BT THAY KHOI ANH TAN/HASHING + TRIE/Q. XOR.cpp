#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int LOG = 31;
int n,m;

struct Node
{
    Node *child[2];
    int exist = 0;
    Node() {child[0] = child[1] = nullptr;}
};

Node *root;

void createNode() {root = new Node();}

void add_nums(int nums)
{
    Node *p = root;
    for(int i = LOG;i >= 0;i--) {
        int bit = nums >> i & 1;
        if(p -> child[bit] == nullptr) p -> child[bit] = new Node();
        p = p -> child[bit];
    }
    p -> exist++;
}

ll query(ll b)
{
    Node *p = root;
    ll res = 0;
    for(int i = LOG;i >= 0;i--) {
        int bit = b >> i & 1;
        if(bit == 1) {
            if(p -> child[0] != nullptr) {
                res += (1 << i);
                p = p -> child[0];
            }
            else p = p -> child[1];
        }


        if(bit == 0) {
            if(p -> child[1] != nullptr) {
                res += (1 << i);
                p = p -> child[1];
            }
            else p = p -> child[0];
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        add_nums(a);
    }
    cin >> m;
    while(m--) {
        ll b;
        cin >> b;
        ll x = query(b);
        x = b ^ x;
        cout << x << ' ';
    }
    return 0;
}