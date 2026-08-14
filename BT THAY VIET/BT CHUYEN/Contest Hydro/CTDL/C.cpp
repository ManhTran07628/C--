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
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(i);
            continue;
        }
        if(!st.empty() &&  ((s[i] == ')' && s[st.top()] == '(') || (s[i] == ']' && s[st.top()] == '[')
        || ( s[i] == '}' && s[st.top()] == '{')) )  {
            st.pop();
            continue;
        }
        cout << "false";
        return 0;

    }
    cout << (st.empty() ? "true" : "false");
    return 0;
}