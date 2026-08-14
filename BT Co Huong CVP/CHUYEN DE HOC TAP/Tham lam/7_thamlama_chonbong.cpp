#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,k;
int c[MM],Cnt[MM];


void solve()
{
    priority_queue<int> q;
    for(int i = 1;i <= k;i++) {
        if(Cnt[i] > 0)
            q.push(Cnt[i]);
    }
    int ans = 0;
    while(q.size() > 0) {
        int a = q.top(); q.pop();
        if(!q.size()) break; 
        int b = q.top(); q.pop();
        ans += 2;
        a--; b--;
        if(a > 0) q.push(a);
        if(b > 0) q.push(b);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        Cnt[c[i]]++;
    }
    solve();
    return 0;
}