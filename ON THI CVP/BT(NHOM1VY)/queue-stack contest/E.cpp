#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
stack<ll> st;
ll a[N];
map<ll,ll> b;
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
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        while(!st.empty() && a[i] > a[st.top()]) 
        {
            ans++;
            b[a[st.top()]]--;
            st.pop();
        }
        ans += b[a[i]];
        if(st.size() > b[a[i]]) ans++;
        st.push(i);
        b[a[i]]++;
    }
    cout << ans;
    return 0;
}