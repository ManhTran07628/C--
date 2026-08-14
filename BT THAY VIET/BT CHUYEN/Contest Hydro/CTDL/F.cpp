#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;

stack<char> st;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    string s;
    cin >> n >> k >> s;
    st.push(s[0]);
    for(int i = 1;i < n;i++) {
        while(!st.empty() && st.top() < s[i] && k > 0) {
            st.pop();
            k--;
        } 
        st.push(s[i]);
    }
    string ans;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}