#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,q,ans[MM],L[MM],R[MM],oldpos[MM];
pii a[MM];
struct Query{int l,r,k,id;} qr[MM];
map<int,int> oval;
vector<int> queries[MM];

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(a[i].fi);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(v.begin(),v.end(),a[i].fi) - v.begin() + 1;
        oval[pos] = a[i].fi;
        a[i].fi = pos;
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

int getquery(int l,int r)
{
    return get(r) - get(l-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    coordcompress();
    sort(a+1,a+n+1);
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        qr[i].id = i;
        L[i] = 1, R[i] = n, ans[i] = -1;
    }


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

            for(auto i : queries[mid]) {
                int l = qr[i].l, r = qr[i].r, k = qr[i].k;
                int id = qr[i].id;
                if(getquery(l,r) >= k) {
                    ans[id] = mid;
                    R[id] = mid - 1;
                }
                else L[id] = mid + 1;

            }
            queries[mid].clear();
        }

        fill(bit+1,bit+n+1,0);
    }

    for(int i = 1;i <= q;i++) cout << oval[ ans[i] ] << '\n';
    return 0;
}