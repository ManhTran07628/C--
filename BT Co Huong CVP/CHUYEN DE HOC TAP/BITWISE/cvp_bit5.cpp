#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int LOG = 31;
int q;

struct Node
{
    Node *child[2];
    int cnt = 0;
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
        p -> cnt++;
    }
}

void del_nums(Node *p,int nums,int i)
{
    if(p != root) p -> cnt--;
    // if(i < 0) return;
    if(i >= 0) {
        int bit = (nums >> i) & 1;
        del_nums(p -> child[bit],nums,i-1);
    }
    // if(p -> cnt == 0) delete(p);
}

ll find_max_xor(int nums)
{
    Node *p = root;
    ll res = 0;
    for(int i = LOG;i >= 0;i--) {
        int bit = nums >> i & 1;
        if(bit == 1) {
            if(p -> child[0] != nullptr && p -> child[0] -> cnt > 0) {
                res += (1 << i);
                p = p -> child[0];

            }
            else p = p -> child[1];
        }
        else {
            if(p -> child[1] != nullptr && p -> child[1] -> cnt > 0) {
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
    cin >> q;
    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        if(c == '+') add_nums(x);
        else if(c == '-') del_nums(root,x,LOG);
        else cout << find_max_xor(x) << '\n';
    }
    return 0;
}