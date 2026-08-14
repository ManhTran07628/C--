#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
const int BLOCK_SIZE = 450;
int n,a[MM],q;
int lazy[MM / BLOCK_SIZE + 2][101];


void fix(int L)
{
    int b = (L + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int u = (b - 1) * BLOCK_SIZE + 1;
    int v = BLOCK_SIZE * b;
    
    for(int i = u;i <= min(v,n);i++) 
        a[i] = lazy[b][ a[i] ];
    
    for(int i = 1;i <= 100;i++)
        lazy[b][i] = i;
}

void ManualUpdate(int L,int R,int oval,int nval)
{
    fix(L);
    for(int i = L;i <= R;i++)
        if(a[i] == oval)
            a[i] = nval;
}

void update(int L,int R,int oval,int nval)
{   
    int BLOCK_L = (L + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int BLOCK_R = (R + BLOCK_SIZE - 1) / BLOCK_SIZE;

    if(BLOCK_L == BLOCK_R) {
        ManualUpdate(L,R,oval,nval);
        return;
    }

    for(int i = BLOCK_L + 1;i < BLOCK_R;i++)
        for(int j = 1;j <= 100;j++)
            if(lazy[i][j] == oval) lazy[i][j] = nval;

    ManualUpdate(L,BLOCK_L * BLOCK_SIZE,oval,nval);
    ManualUpdate((BLOCK_R - 1) * BLOCK_SIZE + 1,R,oval,nval);

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i * BLOCK_SIZE < MM;i++) {
        for(int j = 1;j <= 100;j++)
            lazy[i][j] = j;
    }
    cin >> q;
    while(q--) {
        int l,r,x,y; cin >> l >> r >> x >> y;
        update(l,r,x,y);
    }
    
    for(int i = 1;(i - 1) * BLOCK_SIZE <= n;i++)
        fix((i - 1) * BLOCK_SIZE + 1);

    for(int i = 1;i <= n;i++)
        cout << a[i] << ' ';
    return 0;
}