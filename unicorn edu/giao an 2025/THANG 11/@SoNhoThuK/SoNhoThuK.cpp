#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n,q,L[MM],R[MM],ans[MM];
pair<int,int> a[MM];
vector<int> mid[MM],bit;
struct QR{int l,r,k;};
vector<QR> queries;


void update(int x,int val)
{
    for(; x <= n; x += (x & -x)) 
        bit[x] += val;
}

int get(int x)
{
    int res = 0;
    for(; x > 0; x -= (x & -x))
        res += bit[x];
    return res;
}

bool check(int l,int r,int lim)
{
    return get(r) - get(l-1) >= lim;
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
        for(int i = 0;i <= n;i++) {
            if(i > 0) update(a[i].se,1);

            for(auto id : mid[i]) {
                if(check( queries[id].l, queries[id].r, queries[id].k )) {
                    ans[id] = a[i].fi;
                    R[id] = i - 1;
                }
                else L[id] = i + 1;
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
    bit.resize(n + 7);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a+1,a+n+1);

    queries.resize(q + 7);
    for(int i = 1;i <= q;i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].k;
    }
    for(int i = 1;i <= q;i++) 
        L[i] = 0, R[i] = n, ans[i] = -1;

    solve();
    return 0;
}