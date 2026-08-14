#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int blockSize = 450;
int n,a[MM],q,cnt[MM],cntLow[MM / blockSize + 5],ans[MM];
struct Query{int l,r,x,id;} qr[MM];

bool cmp(Query x,Query y)
{
    int pa = x.l / blockSize;
    int pb = y.l / blockSize;
    if(pa != pb) return pa < pb;
    return x.r < y.r;
}

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(a[i]);
    for(int i = 1;i <= q;i++) v.push_back(qr[i].x);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++)
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
    for(int i = 1;i <= q;i++) 
        qr[i].x = lower_bound(v.begin(),v.end(),qr[i].x) - v.begin() + 1;
}


void update_query(int x,int type)
{
    int block_x = (x + blockSize - 1) / blockSize;
    cntLow[block_x] += type;
    cnt[x] += type;
}

int get_query(int x)
{
    int block_x = (x + blockSize - 1) / blockSize;
    int res = 0;
    if(block_x == 1) {
        for(int i = 1;i <= x;i++) res += cnt[i];
        return res;
    }
    for(int i = 1;i < block_x;i++) res += cntLow[i];
    for(int i = (block_x - 1) * blockSize + 1;i <= x;i++) res += cnt[i];
    return res;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> q;
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].x;
        qr[i].id = i;
    }
    coordcompress();
    sort(qr+1,qr+q+1,cmp);
    int L = 1, R = 0;
    for(int i = 1;i <= q;i++) {
        while(L < qr[i].l) update_query(a[L++],-1);
        while(L > qr[i].l) update_query(a[--L],1);
        while(R < qr[i].r) update_query(a[++R],1);
        while(R > qr[i].r) update_query(a[R--],-1);
        ans[ qr[i].id ] = get_query(qr[i].x);
        // cout << cntLow[1] << '\n';
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

    return 0;
}