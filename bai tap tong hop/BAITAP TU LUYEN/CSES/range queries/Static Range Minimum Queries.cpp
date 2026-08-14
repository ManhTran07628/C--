#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,q;
int x[MM];




int DnC(int L,int R)
{
    if(L == R) return x[L];
    int mid = (L + R) / 2;
    return min(DnC(L,mid), DnC(mid+1,R));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> x[i];
    int f = *min_element(x+1,x+n+1);
    while(q--) {
        int l,r; cin >> l >> r;
        if(l == 1 && r == n) cout << f << '\n';
        else cout << DnC(l,r) << '\n';
    }
    return 0;
}