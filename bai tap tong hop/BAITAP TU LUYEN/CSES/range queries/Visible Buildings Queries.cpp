#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int LOG = 18;
int n,q;
ll a[MM],h[MM],up[MM][LOG + 1];


int bin_lift(int u,int r)
{
    int cnt = 1;
    for(int j = LOG;j >= 0;j--)
        if(up[u][j] <= r) {
            cnt += (1 << j);
            u = up[u][j];
        }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    stack<int> st;
    a[n + 1] = oo;
    st.push(n + 1);
    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[i] >= a[st.top()]) st.pop();
        h[i] = st.top();
        st.push(i);
    }
    for(int i = 1;i <= n;i++) {
        up[i][0] = h[i];
    }
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++) {
            int nxt = up[ up[i][j-1] ][j-1];
            up[i][j] = (nxt == 0 ? n + 1 : nxt);
        }
    // cout << up[1][0] << '\n';
    while(q--) {
        int l,r; cin >> l >> r;
        cout << bin_lift(l,r) << '\n';
    }
    return 0;
}