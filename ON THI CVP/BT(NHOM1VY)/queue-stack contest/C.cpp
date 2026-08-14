#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],trai[N],phai[N];
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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        a[0]=a[n+1]=-1;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        ll ans = 0,l = 0,r = 0;
        st.push(0);
        for(int i = 1;i <= n;i++) {
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            trai[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n+1);
        for(int i = n;i >= 1;i--) {
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            phai[i] = st.top()-1;
            st.push(i);
        }

        for(int i = 1;i <= n;i++) {
            ll x = (phai[i] - trai[i] + 1)*a[i];
            if(x > ans) {
                l = trai[i];
                r = phai[i];
                ans = x;
            }
        }
        cout << ans << ' ' << l << ' ' << r << '\n';
        while(!st.empty()) st.pop();
    }
    return 0;
}