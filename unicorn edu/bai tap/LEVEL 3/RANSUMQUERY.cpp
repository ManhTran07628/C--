#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int blockSize = 320;
int n,q;
ll a[MM],sum[MM / blockSize + 1];

void update(int k,ll val)
{
    int blockK = (k + blockSize - 1) / blockSize;
    sum[blockK] -= a[k];
    a[k] = val;
    sum[blockK] += a[k];
}

ll query(int L,int R)
{
    int blockL = (L + blockSize - 1) / blockSize;
    int blockR = (R + blockSize - 1) / blockSize;
    ll res = 0;
    if(blockL == blockR) {
        for(int i = L;i <= R;i++) res += a[i];
        return res;
    }

    for(int i = blockL + 1;i < blockR;i++) res += sum[i];
    for(int i = L;i <= blockL * blockSize;i++) res += a[i];
    for(int i = (blockR - 1) * blockSize + 1;i <= R;i++) res += a[i];
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll s = 0;
    for(int i = 1;i <= n;i++) {
        int curBlock = (blockSize + i - 1) / blockSize;
        sum[curBlock] += a[i];
    }

    while(q--) {
        int type,l,r; cin >> type >> l >> r;
        if(type == 1) update(l,r);
        else cout << query(l,r) << '\n';
    }
    return 0;
}