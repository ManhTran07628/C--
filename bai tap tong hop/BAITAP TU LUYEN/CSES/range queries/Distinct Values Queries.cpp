#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e6 + 7;
const int blockSize = 450;
int n,q,x[MM],cnt[MM],cur_res = 0,ans[MM];
struct QR{int l,r,id;} qr[MM];

bool cmp(QR a,QR b)
{
    if(a.l / blockSize != b.l / blockSize) return a.l / blockSize < b.l / blockSize;
    return a.r > b.r;
}

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(x[i]);
    sort(v.begin(),v.end());
    for(int i = 1;i <= n;i++)
        x[i] = lower_bound(v.begin(),v.end(),x[i]) - v.begin() + 1;
}


void query(int val,int type)
{
    if(type == 1) {
        cnt[val]++;
        if(cnt[val] == 1) cur_res++;
    }
    else {
        cnt[val]--;
        if(cnt[val] == 0) cur_res--;
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
    for(int i = 1;i <= n;i++) cin >> x[i];
    coordcompress();
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1,r = 0;
    for(int i = 1;i <= q;i++) {
        while(l < qr[i].l) query(x[l++],-1);
        while(l > qr[i].l) query(x[--l],1);
        while(r < qr[i].r) query(x[++r],1);
        while(r > qr[i].r) query(x[r--],-1);
        ans[ qr[i].id ] = cur_res;
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}