#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int LOG = 40;
int n,a[MM];


struct Node{
    Node *child[2];

    Node() {
        child[0] = child[1] = NULL;
    }
};

Node *root;

void make_Node()
{
    root = new Node();
}

void add_nums(ll x)
{
    Node *p = root;
    for(int i = LOG;i >= 0;i--) {
        int Bit = (x >> i) & 1;
        if(p -> child[Bit] == NULL) p -> child[Bit] = new Node();
        p = p -> child[Bit];
    }
}

ll find_xor(ll x)
{
    Node *p = root;
    ll res = 0;
    for(int i = LOG;i >= 0;i--) {
        int Bit = (x >> i) & 1;
        if(Bit == 1) {
            if(p -> child[0] != NULL) {
                res += (1 << i);
                p = p -> child[0];
            }
            else p = p -> child[1];
        }
        else { // Bit = 0
            if(p -> child[1] != NULL) {
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
    make_Node();
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll res = a[1];
    add_nums(a[1]);
    for(int i = 2;i <= n;i++) {
        res = max(res,find_xor(a[i]));
        add_nums(a[i]);
    }
    cout << res;
    return 0;
}