#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5;
ll n, m, v[MM + 7], h[MM + 7], q;
ll pf1[MM + 7], pf2[MM + 7];
ll dp1[MM + 7], dp2[MM + 7], dprev[MM + 7];
stack<int> st;

void process()
{
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && h[st.top()] < h[i]) st.pop();
        if(st.empty()) dp1[i] = v[i] * h[i] - pf1[i];
        else dp1[i] = dp1[st.top()] + (v[i] - v[st.top()]) * h[i] - (pf1[i] - pf1[st.top()]);
        st.push(i);
    }
    
    while(!st.empty()) st.pop();

    for(int i = n;i >= 1;i--) {
        while(!st.empty() && h[st.top()] < h[i]) st.pop();
        if(st.empty()) dp2[i] = (m - v[i]) * h[i] - pf2[i];
        else dp2[i] = dp2[st.top()] + (v[st.top()] - v[i]) * h[i] - (pf2[i] - pf2[st.top()]);
        st.push(i);
    }
}

ll bins(ll k, ll *dp)
{
    int l = 1, r = n, res = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(dp[mid] < k) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i];
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
        pf1[i] = pf1[i-1] + h[i];
    }
    for(int i = n;i >= 1;i--)
        pf2[i] = pf2[i+1] + h[i];
    process();
    for(int i = 1;i <= n;i++) dprev[i] = dp2[n - i + 1];
    // for(int i = 1;i <= n;i++) cout << dp2[i] << ' '; cout << '\n';
    
    int q; cin >> q;
    while(q--) {
        ll k; cin >> k;
        ll L = bins(k,dp1), R = bins(k,dprev);
        if(L + R >= n) cout << n << '\n';
        else cout << L + R << '\n';
    }



    
    return 0;
}
