#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;

stack<int> st;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s = ')' + s;
    int maxlen = 0,cnt = 0;
    st.push(-1);
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(') st.push(i);
        else {
            st.pop();
            if(st.empty()) st.push(i);
            else maxlen = max(maxlen,i-st.top());
        }
    }
    while(!st.empty()) st.pop();
    st.push(-1);
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(') st.push(i);
        else {
            st.pop();
            if(st.empty()) st.push(i);
            else {
                if(i-st.top() == maxlen) cnt++;
            }
        }
    }
    cout << maxlen << ' ' << (!maxlen ? 1 : cnt);
    return 0;
}