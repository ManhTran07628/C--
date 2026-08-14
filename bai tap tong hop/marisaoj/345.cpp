#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,q,a[MM],L[MM],R[MM],ans[MM];

struct QR{int l,r,x,a,id;} qr[MM];
vector<int> queries[MM],bit;
vector<int> process[MM];

void update(int x,int val)
{
    for(;x < MM;x += (x & -x)) bit[x] += val;
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
    bit.resize(MM + 7);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].x >> qr[i].a;
        qr[i].id = i;
        process[ qr[i].x ].push_back(i);
        L[i] = 1, R[i] = n; ans[i] = -1; 
    }

    for(int i = 1;i <= n;i++) {
        if(i > 1) update( a[i-1] ,1);
        for(auto x:process[i]) {
            qr[x].a += getquery(qr[x].l,qr[x].r);
            // cout << i << ' ' << x << ' ' << getquery(qr[x].l,qr[x].r) << '\n';
        }
    }

    // for(int i = 1;i <= q;i++) 
    //     cout << qr[i].l << ' ' << qr[i].r << ' ' << qr[i].x << ' ' << qr[i].a << '\n';

    fill(bit.begin(),bit.end(),0);
    while(1) {
        bool ok = 1;
        for(int i = 1;i <= q;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            queries[ (L[i] + R[i]) / 2 ].push_back(i);
        }
        if(ok) break;
        int i = 1;

        for(int mid = 1;mid <= n;mid++) {

            update(a[ mid ],1);

            for(auto id : queries[mid]) {
                int l = qr[id].l, r = qr[id].r, x = qr[id].x, a = qr[id].a;
                if(getquery(l,r) >= a) {
                    ans[ qr[id].id ] = mid;
                    R[id] = mid - 1;
                }
                else L[id] = mid + 1;
            }

            queries[mid].clear();
        }
        fill(bit.begin(),bit.end(),0);
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << ' ';

    return 0;
}