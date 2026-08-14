#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll d[MM],x[MM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> x[i];
    while(m--)
    {
        int t, r;
        cin >> t >> r;
        int i = lower_bound(x+1,x+t+1,x[t] - r)-x;
        int j = upper_bound(x+t+1,x+n+1,x[t] + r)-x-1;
        d[i]++, d[j + 1]--;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
        if(d[i] > 0) ans++;
    }
    cout << ans;

    return 0;
}
