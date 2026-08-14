#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,q,a[MM],L[MM],R[MM],ans[MM],sz;

struct Node{ll a,w,id;} D[MM];
struct query{int l,r; ll T;} qr[MM];
vector<int> queries[MM];

ll bit[MM];

void update(int x,ll val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

ll get(int x)
{
    ll res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

ll get_range(int l,int r)
{
    return get(r) - get(l - 1);
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
    vector<int> vec;
    vec.push_back(0);
    for(int i = 1;i <= n;i++) {
        cin >> D[i].a >> D[i].w;
        D[i].id = i;
        vec.push_back(D[i].a);
    }
    sort(D+1,D+n+1,[] (Node a,Node b){return a.a < b.a;});
    sort(vec.begin() + 1,vec.end());
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].T;
        L[i] = 1, R[i] = vec.size() - 1;
        ans[i] = -1;
    }
    sz = vec.size() - 1;

    while(1) {
        bool ok = 1;
        for(int i = 1;i <= q;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            queries[ (L[i] + R[i]) / 2 ].push_back(i);
        }

        if(ok) break;
        for(int i = 1, j = 1;i <= sz;i++) {
            while(j <= n && D[j].a <= vec[i]) {
                update(D[j].id,D[j].w);
                j++;
            }

            for(auto id:queries[i]) {
                ll val = get_range(qr[id].l,qr[id].r);
                if(val >= qr[id].T) {
                    ans[id] = vec[i];
                    R[id] = i - 1;
                }
                else L[id] = i + 1;
            }

            queries[i].clear();
        }

        for(int i = 1;i <= n;i++) bit[i] = 0;
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}