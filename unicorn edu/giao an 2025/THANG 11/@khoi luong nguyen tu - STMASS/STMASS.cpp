#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int mp[256],t;
stack<int> st;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        if(s[i] == '(') st.push(0);
        else if(s[i] == ')') {
            ll cur = 0;
            while(!st.empty() && st.top() != 0) {
                cur += st.top();
                st.pop();
            }
            st.pop();
            st.push(cur);
        }
        else {
            if(isdigit(s[i])) {
                ll cur = st.top(); st.pop();
                st.push(cur * (s[i] - '0'));
            }
            if(s[i] == 'C' || s[i] == 'H' || s[i] == 'O') st.push( mp[ s[i] ] );
        }
    }
    ll res = 0;
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mp['C'] = 12;
    mp['H'] = 1;
    mp['O'] = 16;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}