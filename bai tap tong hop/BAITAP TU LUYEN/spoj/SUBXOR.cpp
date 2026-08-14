#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n,k,a[MM];

struct Node
{
    Node *child[2];
    int cnt = 0;
    Node() {child[0] = child[1] = nullptr;}
};

Node *root;

void createnode() {root = new Node();}

void add_nums(int s)
{
    Node *p = root;
    for(int i = 18;i >= 0;i--) {
        int Bi = (s >> i) & 1;
        if(p -> child[Bi] == nullptr) p -> child[Bi] = new Node();
        p = p -> child[Bi];
        p -> cnt++;
    }
}

ll find_prefix(int K,int P)
{
    Node *p = root;
    ll ans = 0;
    for(int i = 18;i >= 0;i--) {
        if(p == nullptr) break;

        int Ki = (K >> i) & 1;
        int Pi = (P >> i) & 1;
        if(Ki == 1) {
            if(p -> child[Pi] != nullptr)
                ans += p -> child[Pi] -> cnt; // Pi ^ Pi = 0
            
            p = p -> child[Pi ^ 1]; // 1 ^ 1 = 0, 1 ^ 0 = 0
        }
        else p = p -> child[Pi];
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        createnode();
        add_nums(0);
        cin >> n >> k;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int prefix = 0;
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            prefix = prefix ^ a[i];
            ans += find_prefix(k,prefix);
            add_nums(prefix);
        }
        cout << ans << '\n';
    }
    return 0;
} 