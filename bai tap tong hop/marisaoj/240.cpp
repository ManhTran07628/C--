#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int n,a[MM];

struct Node
{
    Node *child[2];
    Node() {child[0] = child[1] = NULL;}
};

Node *root;

void createNode() {root = new Node();}

void add_nums(ll x)
{
    Node *p = root;
    for(int i = 30;i >= 0;i--) {
        int BIT = (x >> i) & 1;
        if(p -> child[BIT] == NULL) p -> child[BIT] = new Node();
        p = p -> child[BIT];
    }
}

ll find_max_XOR(ll x)
{
    ll res = 0;
    Node *p = root;
    for(int i = 30;i >= 0;i--) {

        int BIT = (x >> i & 1);
        if(BIT == 1) {
            if(p -> child[0] != NULL) {
                res += 1 << i;
                p = p -> child[0];
            }
            else p = p -> child[1];
        }
        else {
            if(p -> child[1] != NULL) {
                res += 1 << i;
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    add_nums(a[1]);
    ll res = a[1];
    for(int i = 2;i <= n;i++) {
        res = max(res,find_max_XOR(a[i]));
        add_nums(res);
        add_nums(a[i]);
    }
    cout << res;
    return 0;
}