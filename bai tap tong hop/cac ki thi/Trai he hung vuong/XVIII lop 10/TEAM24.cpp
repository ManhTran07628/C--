#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 2e9
const int MM = 1e6 + 7;
int n,a[MM],L[MM],R[MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    stack<int> st1,st2;
    a[0] = oo;
    st1.push(0);
    for(int i = 1;i <= n;i++) {
        while(!st1.empty() && a[st1.top()] < a[i]) st1.pop();
        L[i] = st1.top();
        st1.push(i);
    }

    a[n + 1] = oo;
    st2.push(n + 1);
    for(int i = n;i >= 1;i--) {
        while(!st2.empty() && a[st2.top()] < a[i]) st2.pop();
        R[i] = st2.top();
        st2.push(i);
    }

    ll res = 0;
    for(int i = 1;i <= n;i++) {
        res += i - L[i] - 1;
        res += R[i] - i - 1;
    }
    cout << res;
    return 0;
}