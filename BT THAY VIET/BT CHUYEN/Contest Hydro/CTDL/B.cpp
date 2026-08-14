#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int mp[MM];
stack<int> st;
bool check(char x,char y)
{
    return ( (x == '(' && y == ')') || (x == '[' && y == ']') );
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,ans;
    cin >> s;
    for(int i = 0;i < s.size();i++) {

        if(s[i] == '(' || s[i] == '[') st.push(i);
        else if(!st.empty() && check( s[st.top()], s[i] )) {
            mp[st.top()] = mp[i] = 1;
            st.pop();
        }

    }
    for(int i = 0;i < s.size();i++) {
        // cout << mp[i];
        if(mp[i]) ans += s[i];
        else {
            if(s[i] == '(' || s[i] == ')') ans += "()";
            else if(s[i] == '[' || s[i] == ']') ans += "[]";
        }
    }
    cout << ans;
    return 0;
}
