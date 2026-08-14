#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 3e7+7;
ll a[N];
stack<ll> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tower"
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
    ll cnt = 1;
    st.push(1);
    for(int i = 2;i <= n;i++) {
        if(a[i] <= a[st.top()]) {
            st.pop();
            st.push(i);
        }
        else {
            cnt++;
            while(!st.empty() && a[i] > a[st.top()]) st.pop();
            if(st.empty()) {
                st.push(i);
            }
            else {
                st.pop();
                st.push(i);
            }
        }
    }
    cout << cnt;
    return 0;
}