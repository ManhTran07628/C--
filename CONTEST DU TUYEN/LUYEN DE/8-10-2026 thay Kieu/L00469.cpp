#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n,q;
pii a[MM];
struct QR{int l,r,k,id;} qr[MM];
vector<int> old;
pii ans[MM];

ll bitsz[MM],bitF[MM],bitB[MM];

void update(int x,ll val,ll bit[])
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

ll get(int x,ll bit[])
{
    ll res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

ll getrange(int l,int r,ll bit[])
{
    return get(r,bit) - get(l - 1,bit);
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
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        qr[i].id = i;
    }
    
    sort(qr+1,qr+q+1,[] (QR a,QR b){
        if(a.r != b.r) return a.r < b.r;
        return a.l < b.l;
    });

    sort(a+1,a+n+1);
    for(int i = 1;i <= q;i++) {
        // cout << qr[i].l << ' ' << qr[i].r << ' ' << qr[i].k << '\n';
        old.push_back(qr[i].id);
    }

    // for(int i = 1;i <= n;i++) cout << a[i].fi << ' ' << a[i].se << '\n';

    for(int i = 1;i <= n;i++) {

        update(a[i].se,a[i].fi,bitF);
        update(a[i].se,1,bitsz);

        vector<int> nxt;
        for(auto query:old) {
            int l = qr[query].l, r = qr[query].r, k = qr[query].k;

            // cout << l << ' ' << r << ' ' << k << ' ' << getrange(l,k,bitsz) << '\n';
            if(getrange(l,r,bitsz) == k) {

                ll sum = getrange(l,r,bitF);
                ll k_th = sum - getrange(l,r,bitB);
                ans[ qr[query].id ] = {k_th,sum};
                continue;
            }
            
            nxt.push_back(query);
        } 

        old = nxt;

        update(a[i].se,a[i].fi,bitB);
    }

    for(int i = 1;i <= q;i++) cout << ans[i].fi << ' ' << ans[i].se << '\n';
    return 0;
}
