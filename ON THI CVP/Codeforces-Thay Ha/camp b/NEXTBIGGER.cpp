#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
stack<ll> st;
ll a[N];
vector<ll> f;
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
    a[n+1] = 1e9;
    st.push(n+1);
    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[i] >= a[st.top()]) st.pop();
        if(st.top() == n+1) f.push_back(0);
        else f.push_back(st.top());
        st.push(i);
    }
    reverse(f.begin(),f.end());
    for(auto i:f) {
        cout << i << '\n';
    }
    return 0;
}