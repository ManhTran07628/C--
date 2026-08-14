#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int t,n;
int a[MM],L[MM],R[MM];

void solve()
{
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    stack<int> st;
    st.push(0);
    a[0] = -1e9;
    for(int i = 1;i <= n;i++) {
        while(a[st.top()] >= a[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    a[n+1] = -1e9;
    for(int i = n;i >= 1;i--) {
        while(a[st.top()] >= a[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,1ll * (R[i] - L[i] - 1) * a[i]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}