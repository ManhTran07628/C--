#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,q,ans[MM],L[MM],R[MM];

pii a[MM];

struct Query{int l,r,k;} qr[MM];

vector<int> queries[MM];

vector<int> vec;
void coordcompress()
{
    for(int i = 1;i <= n;i++) vec.push_back(a[i].fi);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 1;i <= n;i++) {
        a[i].se = i;
    }
}

int bit[MM];

void update(int x,int val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

int get(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
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
    for(int i = 1;i <= n;i++) cin >> a[i].fi;
    coordcompress();
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        ans[i] = -1;
        L[i] = 1, R[i] = n;
    }
    sort(a+1,a+n+1);

    // for(int i = 1;i <= n;i++) cout << a[i].fi << ' ' << a[i].se << '\n';

    while(1) {
        bool ok = 1;
        for(int i = 1;i <= q;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            queries[ (L[i] + R[i]) / 2 ].push_back(i);
        }
        if(ok) break;

        for(int mid = 1;mid <= n;mid++) {
            update(a[mid].se,1);
            for(auto id:queries[mid]) {
                int l = qr[id].l, r = qr[id].r, k = qr[id].k;
                if(get(r) - get(l - 1) >= k) {
                    // cout << l << ' ' << r << ' ' << k << ' ' << get(r) - get(l - 1) << '\n';
                    ans[id] = mid;
                    R[id] = mid - 1;
                }
                else L[id] = mid + 1;
            }
            queries[mid].clear();
        }
        fill(bit+1,bit+n+1,0);
    }

    for(int i = 1;i <= q;i++) {
        cout << a[ ans[i] ].fi << '\n';
        // cout << vec[ ans[i] ] << '\n';
    }
    return 0;
}