#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int blockSize = 1001;
int n,t,a[MM],cnt[MM];
ll ans[MM],cur_res = 0;
struct QR{int l,r,id;} qr[MM];

bool cmp(QR a, QR b)
{
    int Pa = (a.l + blockSize - 1) / blockSize;
    int Pb = (b.l + blockSize - 1) / blockSize;
    if(Pa != Pb) return Pa < Pb;
    return a.r < b.r;
}

void query(int L,int x)
{
    cur_res -= 1ll * cnt[ a[L] ] * cnt[ a[L] ] * a[L];
    cnt[ a[L] ] += x;
    cur_res += 1ll * cnt[ a[L] ] * cnt[ a[L] ] * a[L];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= t;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+t+1,cmp);
    int l = 1,r = 0;
    for(int i = 1;i <= t;i++) {
        while(l < qr[i].l) query(l++,-1);
        while(l > qr[i].l) query(--l,1);
        while(r < qr[i].r) query(++r,1);
        while(r > qr[i].r) query(r--,-1);
        ans[ qr[i].id ] = cur_res;
    }
    for(int i = 1;i <= t;i++) cout << ans[i] << '\n';
    return 0;
}