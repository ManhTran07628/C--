#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int h[MM],L[MM],R[MM];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    stack<int> st;
    st.push(0);
    for(int i = 1;i <= n;i++) {
        while(h[ st.top() ] >= h[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    h[n+1] = 0;
    st.push(n+1);
    for(int i = n;i >= 1;i--) {
        while(h[ st.top() ] >= h[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,(R[i] - L[i] - 1) * 1ll * h[i]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}