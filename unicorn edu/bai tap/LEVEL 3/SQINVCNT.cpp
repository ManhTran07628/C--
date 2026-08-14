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
int n,a[MM],bit[MM / blockSize + 3][lim + 3],bitrev[MM];
ll cur_res = 0;
void update_rev(int x,int val)
{
    for(;x <= lim;x += x & -x) bitrev[x] += val;
}

int get_rev(int x)
{
    int res = 0;
    for(;x > 0;x -= x & -x) res += bitrev[x];
    return res;
}

void update(int id,int x,int val)
{
    for(;x <= lim;x += x & -x) bit[id][x] += val;
}

int get(int id,int x)
{
    int res = 0;
    for(;x > 0;x -= x & -x) res += bit[id][x];
    return res;
}

int getLR(int block,int L,int R)
{
    return get(block,R) - get(block,L-1);
}

int get_range(int L,int R,int x,int y)
{
    if(L > R) return 0;
    int blockL = (L + blockSize - 1) / blockSize;
    int blockR = (R + blockSize - 1) / blockSize;
    int res = 0;
    if(blockL == blockR) {
        for(int i = L;i <= R;i++) res += (x <= a[i] && a[i] <= y);
        return res;
    }

    for(int i = blockL + 1;i < blockR;i++) 
        res += getLR(i,x,y);
    for(int i = L;i <= blockL * blockSize;i++) 
        res += (x <= a[i] && a[i] <= y);
    for(int i = (blockR - 1) * blockSize + 1;i <= R;i++) 
        res += (x <= a[i] && a[i] <= y);
    return res;
}

void query(int x,int y)
{
    if(a[x] == y) return;
    if(a[x] > y) {
        cur_res += get_range(1,x-1,y+1,a[x]);
        cur_res -= get_range(x+1,n,y,a[x]-1);
    }
    else {
        cur_res -= get_range(1,x-1,a[x]+1,y);
        cur_res += get_range(x+1,n,a[x],y-1);
    }

    int blockX = (x + blockSize - 1) / blockSize;
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
        cur_res += get_rev(lim) - get_rev(a[i]);
        update_rev(a[i],1);
        int block = (i + blockSize - 1) / blockSize;
        update(block,a[i],1);
    }
    // cout << 1;

    int q; cin >> q;
    while(q--) {
        int x,y; cin >> x >> y;
        query(x,y);
        cout << cur_res << '\n';
    }
    return 0;
}