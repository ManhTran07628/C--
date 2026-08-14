#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,q,L[MM],R[MM],ans[MM];
struct QR{int l,r,k;} qr[MM];
pii a[MM];
vector<int> queries[MM],bit;

void update(int x)
{
    for(;x <= n;x += (x & -x)) bit[x]++;
}

int get(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

int query(int l,int r)
{
    return get(r) - get(l-1);
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
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        L[i] = 1; R[i] = n; ans[i] = -1;
    }

    while(1) {
        bool ok = 1;
        vector<int> Mid;
        for(int i = 1;i <= q;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            int mid = (L[i] + R[i]) / 2;
            Mid.push_back( mid );
            queries[ mid ].push_back(i);
        }
        sort(Mid.begin(),Mid.end());
        if(ok) break;
        
        int i = 1;
        for(auto mid : Mid) {
            while(i <= n && a[i].fi <= a[mid].fi) {
                update(a[i].se);
                i++;
            }
            for(auto id : queries[mid]) {
                int l = qr[id].l, r = qr[id].r, k = qr[id].k;

                int val = query(l,r);
                if(val >= k) {
                    ans[id] = mid;
                    R[id] = mid - 1;
                } 
                else L[id] = mid + 1;

            }

            queries[mid].clear();
        }
        fill(bit.begin(),bit.end(),0);
    }

    for(int i = 1;i <= q;i++) cout << a[ ans[i] ].fi << '\n';


    return 0;
}