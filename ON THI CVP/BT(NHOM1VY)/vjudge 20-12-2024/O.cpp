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
    string s;
    cin >> n >> s;
    ll cnt = 0;
    for(int i = 0;i < n;i++) {
        if(!st.empty() && s[st.top()] != s[i]) {
            cnt++;
            st.pop();
        }
        else st.push(i);
    }
    if(st.empty()) cout << cnt;
    else cout << -1;
    return 0;
}