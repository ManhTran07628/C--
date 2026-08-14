#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e5+7;
int n,m,k,L[MM],R[MM],ans[MM];
ll lim[MM];
vector<int> query[MM],pos[MM];
vector<ll> bit;

struct qr{int l,r; ll a;};
vector<qr> t;

void update(int x,ll val)
{
    for(; x <= m;x += (x & -x)) 
        bit[x] += val;
}

void updateQR(int l,int r,ll val)
{
    update(l,val);
    update(r+1,-val);
}  

ll get(int x)
{
    ll res = 0;
    for(; x > 0;x -= (x & -x))
        res += bit[x];
    return res;
}

bool check(int id)
{
    ll cnt = 0;
    for(auto x : pos[id]) {
        ll cur = get(x);
        
        cnt += cur;
    }
    return cnt >= lim[id];
}

void solve()
{
    while(1) {
        bool ok = 1;
        for(int i = 1;i <= n;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            query[ (L[i] + R[i]) / 2 ].push_back(i);
        }

        if(ok) break;


        for(int i = 0;i <= k;i++) {
            if(i > 0) {
                int l = t[i].l, r = t[i].r;
                ll w = t[i].a;
                if(l <= r) updateQR(l,r,w);
                else {
                    updateQR(l,m,w);
                    updateQR(1,r,w);
                }
            }

            for(auto id : query[i]) {


                if(check(id)) {
                    R[id] = i - 1;
                    ans[id] = i;
                }
                else L[id] = i + 1;
            }
            query[i].clear();
        }
        fill(bit.begin(),bit.end(),0);
    }

    for(int i = 1;i <= n;i++) {
        cout << ans[i] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    bit.resize(m * 4 + 7);
    for(int i = 1;i <= m;i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    for(int i = 1;i <= n;i++) cin >> lim[i];

    
    cin >> k;
    t.resize(k + 7);
    for(int i = 1;i <= k;i++) {
        cin >> t[i].l >> t[i].r >> t[i].a;
    }

    for(int i = 1;i <= n;i++) {
        L[i] = 0, R[i] = k, ans[i] = -1;
    }
    solve();
    

    return 0;   
}