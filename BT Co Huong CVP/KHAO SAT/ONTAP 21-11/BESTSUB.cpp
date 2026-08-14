#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e6+7;
ll a[MM],L[MM],R[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "bestsub"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    stack<int> st;
    st.push(0);
    a[0] = oo;
    for(int i = 1;i <= n;i++) {
        while(a[ st.top() ] < a[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }
   
    while(!st.empty()) st.pop();
    st.push(n+1);
    a[n+1] = oo;
    for(int i = n;i >= 1;i--) {
        while(a[ st.top() ] < a[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }

    ll res = -oo;
    for(int i = 1;i <= n;i++) {
        if(L[i] >= 1) res = max(res,a[i] - (i - L[i] + 1));
        if(R[i] <= n) res = max(res,a[i] - (R[i] - i + 1));
        // res = max({res, a[i] - (i - v + 1), a[i] - (u - i + 1)});
        // cout << i << ' ' << L[i] << ' ' << R[i] << '\n';
    }
    cout << res;
    return 0;
}