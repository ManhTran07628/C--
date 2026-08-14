#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 250000 + 7;
const int lim = 5e4;
const int blockSize = 500;
int n,q,a[MM],max_block = 0;
ll cur_res = 0;
int bit[MM / blockSize + 1][lim + 1],bitinv[MM];

void upd(int L,int val)
{
    for(;L <= lim;L += (L & -L)) bitinv[L] += val;
}

ll gg(int L)
{
    int res = 0;
    for(;L > 0;L -= (L & -L)) res += bitinv[L];
    return res;
}

void update(int blockL,int L,int val)
{
    for(;L <= lim;L += (L & -L)) bit[blockL][L] += val;
}

ll get(int blockL,int L)
{
    int res = 0;
    for(;L > 0;L -= (L & -L)) res += bit[blockL][L];
    return res;
}


ll getseg(int l,int r,int x,int y)
{
    int blockL = (l + blockSize - 1) / blockSize;
    int blockR = (r + blockSize - 1) / blockSize;
    ll cur = 0;
    if(blockL == blockR) {
        for(int i = l;i <= r;i++) {
            cur += (x <= a[i] && a[i] <= y);
        }
        return cur;
    }
    for(int i = blockL + 1;i < blockR;i++) cur += get(i,y) - get(i,x - 1);
    for(int i = l;i <= blockL * blockSize;i++) cur += (x <= a[i] && a[i] <= y);
    for(int i = (blockR - 1) * blockSize + 1;i <= r;i++) cur += (x <= a[i] && a[i] <= y);
    return cur;
}

void query(int x,int y)
{
    int blockX = (x + blockSize - 1) / blockSize;

    if(a[x] == y) return;
    if(y > a[x]) {
        cur_res -= getseg(1,x-1,a[x]+1,y);
        cur_res += getseg(x+1,n,a[x],y-1);
    }
    else if(a[x] > y) {
        cur_res += getseg(1,x-1,y+1,a[x]);
        cur_res -= getseg(x+1,n,y,a[x]-1);
    }
        
    // update
    update(blockX,a[x],-1);
    a[x] = y;
    update(blockX,a[x],1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) {
        cur_res += gg(lim) - gg(a[i]);
        upd(a[i],1);
        int curBlock = (i + blockSize - 1) / blockSize;
        update(curBlock,a[i],1);
    }
    cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        query(l,r); cout << cur_res << '\n';
    }
    // cout << cur_res;
    return 0;
}
