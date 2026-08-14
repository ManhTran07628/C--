#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,m;
ll a[MM],b[MM],psA[MM],psB[MM],L = 1,R = 0;


ll getstep(int mid)
{
    int posA = upper_bound(a+1,a+n+1,mid) - a - 1;
    
    ll step_a = 1ll * mid * posA - psA[posA];

    int posB = upper_bound(b+1,b+m+1,mid) - b - 1;

    ll step_b = psB[m] - psB[posB] - 1ll * mid * (m - posB);

    return step_a + step_b;
}

void solve()
{
    ll ans = 0;
    while(L <= R) {
        int m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
        if(getstep(m1) < getstep(m2)) {
            ans = m1;
            R = m2 - 1;
        }
        else {
            ans = m2;
            L = m1 + 1;
        }
    }
    cout << getstep(ans);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];
    
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    
    for(int i = 1;i <= m;i++) {
        psB[i] = psB[i-1] + b[i];
        R = max(R,b[i]);
    }
    for(int i = 1;i <= n;i++) {
        psA[i] = psA[i-1] + a[i];
        R = max(R,a[i]);
    }

    solve();
    return 0;
}