#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,k;
struct Node{ll s,t,c;} a[MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].s >> a[i].t >> a[i].c;
        a[i].t += a[i].s - 1;
        // cout << a[i].s << ' ' << a[i].t << ' ' << a[i].c << '\n';
    }
    subtask1::solve();
    return 0;
}