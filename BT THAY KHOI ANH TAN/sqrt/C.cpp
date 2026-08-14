#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int block_size = 320;
int n,a[MM],q,cur_res = 0,cnt[MM],ans[MM];

struct QR{int l,r,id;} qr[MM];


bool cmp(QR a,QR b)
{
    if(a.l / block_size != b.l / block_size) return a.l < b.l;
    return a.r > b.r;
}

void update(int x,int type)
{
    if(x > n) return;

    if(cnt[x] == x) cur_res--;
    if(type == 1) {
        cnt[x]++;
        if(cnt[x] == x) cur_res++;
    }
    else {
        cnt[x]--;
        if(cnt[x] == x) cur_res++;
    }
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1,r = 0;
    for(int i = 1;i <= q;i++) {
        while(l < qr[i].l) update(a[l++],0);
        while(r < qr[i].r) update(a[++r],1);
        while(l > qr[i].l) update(a[--l],1);
        while(r > qr[i].r) update(a[r--],0);

        ans[ qr[i].id ] = cur_res;
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}