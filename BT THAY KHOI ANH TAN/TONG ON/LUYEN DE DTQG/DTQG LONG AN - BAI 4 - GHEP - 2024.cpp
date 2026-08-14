#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 2e5 + 7;
ll n,a[MM],L[MM],R[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "GHEP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    stack<int> st;
    st.push(0); a[0] = a[n+1] = -oo;
    // for(int i = 1;i <= n;i++) cout << a[i] << ' ';
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && a[ st.top() ] >= a[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[ st.top() ] >= a[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        // cout << L[i] << ' ' << R[i] << '\n';
        ll width = min(a[i],R[i] - L[i] - 1);
        res = max(res,width * width);
    }
    cout << res;
    return 0;
}