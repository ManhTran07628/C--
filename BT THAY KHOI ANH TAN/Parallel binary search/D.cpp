#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e5+7;
int n,q,L[MM],R[MM],ans[MM];
pair<int,int> a[MM];
vector<ll> bit_id,bit,mid[MM];
struct QR{int l,r; ll cash;};
vector<QR> qr;


void update(vector<ll> &bit,int x,ll val)
{
    for(; x <= n; x += (x & -x))
        bit[x] += val;
}

ll get(vector<ll> &bit,int x)
{
    ll res = 0;
    for(; x > 0;x -= (x & -x))
        res += bit[x];
    return res;
}

bool check(int l,int r,ll lim)
{
    return get(bit,r) - get(bit,l-1) <= lim;
}

void solve()
{
    while(1) {
        bool ok = 1;
        for(int i = 1;i <= q;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            mid[ (L[i] + R[i]) / 2 ].push_back(i);
        }
        if(ok) break;
        
        fill(bit.begin(),bit.end(),0);
        fill(bit_id.begin(),bit_id.end(),0);

        for(int i = 1;i <= n;i++) {
            update(bit_id,a[i].se,1);
            update(bit,a[i].se,a[i].fi);

            for(auto id: mid[i]) {
                if(check(qr[id].l, qr[id].r ,qr[id].cash)) {
                    ans[id] = get(bit_id,qr[id].r) - get(bit_id,qr[id].l - 1);
                    L[id] = i + 1;
                }
                else R[id] = i - 1;
            }
            mid[i].clear();

        }
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    bit_id.resize(n + 7); bit.resize(n + 7);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a+1,a+n+1);

    qr.resize(q + 7);
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].cash;
    }
    for(int i = 1;i <= q;i++) 
        L[i] = 1,R[i] = n,ans[i] = -1;

    solve();
    return 0;
}