#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;

stack<int> st;

bool check(char x,char y)
{
    if(x == '(' && y == ')') return 1;
    if(x == '[' && y == ']') return 1;
    if(x == '{' && y == '}') return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    st.push(-1);
    int maxlen = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(i);
        else {
            if(check( s[st.top()] , s[i] )) {
                st.pop();
                if(st.empty()) st.push(i);
                else maxlen = max(maxlen,i-st.top());
            }
            else st.push(i);
        }
    }
    cout << maxlen;
    return 0;
}