#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N];
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    st.push(0);
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        l[i] = st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        r[i] = st.top()-1;
        st.push(i);
    }
    for(int i = 1;i <= n;i++) {
        cout << l[i] << ' ';
        // ll rong = r[i] - l[i] + 1;
        // if(rong >= a[i]) ans = max(ans,a[i]);
    }
    cout << '\n';
    for(int i = n;i >= 1;i--) {
        cout << r[i] << ' ';
        // ll rong = r[i] - l[i] + 1;
        // if(rong >= a[i]) ans = max(ans,a[i]);
    }
    return 0;
}