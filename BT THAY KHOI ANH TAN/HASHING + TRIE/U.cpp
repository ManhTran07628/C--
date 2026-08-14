#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int LOG = 31;
int n,k;
int a[MM];

struct Node
{
    Node *child[2];
    ll cnt = 0;
    Node() {child[0] = child[1] = nullptr;}
};

Node *root;

void createNode() {root = new Node();}

void add_nums(ll nums,ll cnt)
{
    Node *p = root;
    for(int i = LOG;i >= 0;i--) {
        int bit = (nums >> i) & 1;
        if(p -> child[bit] == nullptr) p -> child[bit] = new Node();
        p = p -> child[bit];
        p -> cnt += cnt;
    }
}

ll query(ll x,ll k)
{
    Node *p = root;
    ll res = 0;
    for(int i = LOG;i >= 0;i--) {
        if(p == nullptr) break;
        int bitx = (x >> i) & 1;
        int bitk = (k >> i) & 1;
        if(bitk == 0) { 
            if(p -> child[bitx ^ 1] != nullptr) {
                res += p -> child[bitx ^ 1] -> cnt;
            } 
            p = p -> child[bitx];
        }
        else p = p -> child[bitx];
    }
    if(p != nullptr) res += p -> cnt;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    createNode();
    cin >> n >> k;
    add_nums(0,1);
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] ^= a[i-1];
        ll get = query(a[i],k);
        add_nums(a[i],get);
        res += get;
    }
    cout << res;
    return 0;
}