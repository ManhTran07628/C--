#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
stack<ll> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    st.push(n+1);
    a[n+1] = 1e18;
    ll ans = 0;
    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[i] > a[st.top()]) st.pop();
        ans += st.top() - i - 1;
        st.push(i);
    }
    cout << ans;
    return 0;
}