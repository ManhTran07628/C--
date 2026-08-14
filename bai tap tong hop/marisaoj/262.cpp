#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5;
const int blockSize = 320;
int n,q,p[MM + 5];
ll cur_res = 0,ans[MM + 5];
struct dl{int l,r,id;} qr[MM + 5];

bool cmp(dl a,dl b)
{
    int pa = (a.l + blockSize - 1) / blockSize;
    int pb = (b.l + blockSize - 1) / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
}

int bit[MM + 5];

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
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> p[i];

    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1, r = 0;
    for(int i = 1;i <= q;i++) {
        // cout << qr[i].l << ' ' << qr[i].r << '\n';
        while(l < qr[i].l) {
            cur_res -= get(p[l] - 1);
            update(p[l],-1);
            l++;
        }
        while(l > qr[i].l) {
            l--;
            cur_res += get(p[l] - 1);
            update(p[l],1);
        }
        while(r < qr[i].r) {
            r++;
            cur_res += get(n) - get(p[r]);
            update(p[r],1);
        }
        while(r > qr[i].r) {
            cur_res -= get(n) - get(p[r]);
            update(p[r],-1);
            r--;
        }
        ans[ qr[i].id ] = cur_res;
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}