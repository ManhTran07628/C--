#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,T;
int x[MM],t[MM];

priority_queue<int> q;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    for(int i = 1;i <= n;i++) {
        cin >> x[i] >> t[i];
    }
    int res = 0, time = 0;
    for(int i = 1;i <= n;i++) {
        time += t[i]; // eat time
        q.push(t[i]);
        while(!q.empty() && time + x[i] > T) {
            time -= q.top();
            q.pop();
        }
        // cout << i << ' ' << time + x[i] << '\n';
        res = max(res,(int) q.size());
    }
    cout << res;
    return 0;
}