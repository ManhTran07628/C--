#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int block_Size = 320;
int n,q,a[MM],sz;
ll cur_res = 0,ans[MM];

struct Query
{
    int l,r,id;
};
vector<Query> qr;

bool cmp(Query x,Query y)
{
    int sa = x.l / block_Size, sb = y.l / block_Size;
    if(sa != sb) return sa < sb;
    return x.r < y.r;
}


void compress()
{
    vector<int> vec;
    for(int i = 1;i <= n;i++) vec.push_back(a[i]);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 1;i <= n;i++) {
        a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
    }
    sz = vec.size();
}

int bit[MM];

void update(int x,int val)
{
    for(;x <= sz;x += (x & -x)) bit[x] += val;
}

int get(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void add_R(int val)
{
    cur_res += get(sz) - get(val);
    update(val,1);
}

void remove_R(int val)
{
    cur_res -= (get(sz) - get(val));
    update(val,-1);
}

void add_L(int val)
{
    cur_res += get(val - 1);
    update(val,1);
}

void remove_L(int val)
{
    cur_res -= get(val - 1);
    update(val,-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    compress();
    for(int i = 1;i <= q;i++) {
        int l,r; cin >> l >> r;
        qr.push_back({l,r,i});
    }
    sort(qr.begin(),qr.end(),cmp);
    int l = 1,r = 0;
    for(int i = 0;i < q;i++) {
        while(l < qr[i].l) remove_L(a[l++]);
        while(l > qr[i].l) add_L(a[--l]);
        while(r < qr[i].r) add_R(a[++r]);
        while(r > qr[i].r) remove_R(a[r--]);

        ans[ qr[i].id ] = cur_res;
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}