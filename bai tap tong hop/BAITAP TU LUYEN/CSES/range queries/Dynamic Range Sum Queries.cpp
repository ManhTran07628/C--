#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int BLOCK_SIZE = 320;
int cnt[MM / BLOCK_SIZE + 1][MM];
int n,q,a[MM];

int get(int l,int r,int val)
{
    int blockL = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int blockR = r / BLOCK_SIZE;

    if(blockL == blockR) 
        return count(a + l,a + r + 1,val);

    
    for(int i = blockL;i <= blockR)

    for(int i = l;i <= l * blockL;i++)
        cnt[]
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) {
        cnt[i / BLOCK_SIZE][ a[i] ]++;
    }
    return 0;
}