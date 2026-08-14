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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    st.push(1);
    cout << 0 << " ";
    for(int i = 2;i <= n;i++) {
        if(a[i] > a[st.top()]) {
            cout << st.top() << " ";
            st.push(i);
        }
        else {
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            if(st.empty()) cout << 0 << " ";
            else cout << st.top() << " ";
            st.push(i);
        }
    }
    return 0;
}