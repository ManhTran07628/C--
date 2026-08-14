#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],a[MAXN],psmin[MAXN];
deque<int> dq;
int n,k;
void minquery()
{
    int j = 1;
    for(int i = 1;i <= n;i++) {
        while(!dq.empty() && dq.front() < i-k+1) dq.pop_front();
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k) {
            psmin[i] = a[dq.front()];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    minquery();
    for(int i = 1;i <= n;i++) {
        dp[i] = dp[i-1];
        if(i >= k) 
            dp[i] = max(dp[i],dp[i-k]+psmin[i]);
    }
    cout << dp[n];
    return 0;
}