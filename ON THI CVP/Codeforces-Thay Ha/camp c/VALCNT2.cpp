#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int d1[MAXN],d2[MAXN],x[MAXN],y[MAXN];
int a[MAXN],b[MAXN];
set<int> s1,s2;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++) {
        d1[a[i]]++;
        d2[b[i]]++;
        s1.insert(a[i]);
        s2.insert(b[i]);
    }
    for(auto i:s1) x[d1[i]]++;
    for(auto i:s2) y[d2[i]]++;
    while(q--) {
        int k;
        cin >> k;
        cout << x[k] << ' ' << y[k] << '\n';
    }
    return 0;
}