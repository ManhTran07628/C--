#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e5 + 7;
const int blockSize = 450;
int n,a[MM],lazy[MM / blockSize + 7][105];


void fix(int L)
{
    int blockL = (L + blockSize - 1) / blockSize;
    for(int i = (blockL - 1) * blockSize + 1;i <= blockL * blockSize;i++) {
        a[i] = lazy[blockL][ a[i] ];
    }

    for(int i = 1;i <= 100;i++)
        lazy[blockL][i] = i;
}

void manualUpdate(int L,int R,int x,int y)
{
    fix(L);
    for(int i = L;i <= R;i++) {
        if(a[i] == x) a[i] = y;
    }
}

void update(int L,int R,int x,int y)
{
    int blockL = (L + blockSize - 1) / blockSize;
    int blockR = (R + blockSize - 1) / blockSize;

    if(blockL == blockR) {
        manualUpdate(L,R,x,y);
        return;
    }

    for(int i = blockL + 1;i < blockR;i++) {
        for(int j = 1;j <= 100;j++) 
            if(lazy[i][j] == x) lazy[i][j] = y;
    }
    manualUpdate(L,blockL * blockSize,x,y);
    manualUpdate((blockR - 1) * blockSize + 1,R,x,y);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    for(int i = 1;(i - 1) * blockSize <= n;i++) {
        for(int j = 1;j <= 100;j++) 
            lazy[i][j] = j;
    }
    int q; cin >> q;
    while(q--) {
        int l,r,x,y; cin >> l >> r >> x >> y;
        update(l,r,x,y);
    }
    for(int i = 1;(i - 1) * blockSize <= n;i++) 
        fix(i * blockSize);
    for(int i = 1;i <= n;i++) cout << a[i] << ' ';
    return 0;
}