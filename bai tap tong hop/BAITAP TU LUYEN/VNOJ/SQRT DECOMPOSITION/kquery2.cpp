#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e4 + 7;
const int lim = 1e4;
const int blockSize = 180;
int n,q,a[MM],bit[(MM / blockSize + 3) * 4][lim + 3];
int st[MM], maxBlock;
void update(int block,int x,int val)
{
    for(;x <= lim;x += (x & -x)) bit[block][x] += val;
}

int get(int block,int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[block][x];
    return res;
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[l] = id;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}

void updateArray(int blockL,int L)
{
    int id = st[blockL];
    while(id > 0) {
        update(id,a[L],1);
        id /= 2;
    }
}

void updatequery(int L,int val)
{
    int blockL = (L + blockSize - 1) / blockSize;
    int id = st[blockL];
    while(id > 0) {
        update(id,a[L],-1);
        id /= 2;
    }
    a[L] = val;
    id = st[blockL];
    while(id > 0) {
        update(id,a[L],1);
        id /= 2;
    }
}

int getrange(int id,int l,int r,int u,int v,int k)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return get(id,lim) - get(id,k);
    int mid = (l + r) / 2;
    return getrange(id*2,l,mid,u,v,k) + getrange(id*2+1,mid+1,r,u,v,k);
}

int getquery(int L,int R,int k)
{
    int blockL = (L + blockSize - 1) / blockSize;
    int blockR = (R + blockSize - 1) / blockSize;
    if(blockL == blockR) {
        int res = 0;
        for(int i = L;i <= R;i++) res += (a[i] > k);
        return res;
    }
    int res = getrange(1,1,maxBlock,blockL+1,blockR-1,k);
    for(int i = L;i <= blockL * blockSize;i++)
        res += (a[i] > k);  
    for(int i = (blockR - 1) * blockSize + 1;i <= R;i++)
        res += (a[i] > k);
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    maxBlock = (n + blockSize - 1) / blockSize;
    build(1,1,maxBlock);
    for(int i = 1;i <= n;i++) {
        int cur_block = (i + blockSize - 1) / blockSize;
        updateArray(cur_block,i);
    }
    cin >> q;
    while(q--) {
        // int type; cin >> type;
        // if(type == 0) {
        //     int i,v; cin >> i >> v;
        //     updatequery(i,v);
        // }
        // else {
            int l,r,k; cin >> l >> r >> k;
            cout << getquery(l,r,k) << '\n';
        // }
    }   
    return 0;
}