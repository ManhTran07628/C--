#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
int n,m;
ll b[MM],a1[MM];
vector<ll> a;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a1[i];
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            a.push_back(a1[i] + a1[j]);
        }

    for(int i = 1;i <= m;i++) cin >> b[i];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    sort(b+1,b+m+1);
    // b_i + b_j == x

    for(auto x: a) {
        for(int i = 1;i <= m;i++) {
            int pos = lower_bound(b+i+1,b+m+1,x - b[i]) - b;
            if(b[i] + b[pos] == x) {
                cout << x;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}