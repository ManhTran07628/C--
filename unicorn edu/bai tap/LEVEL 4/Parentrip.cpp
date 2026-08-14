#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;

stack<int> st;
bool solve()
{
    while(!st.empty()) st.pop();
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        if(s[i] == '(') st.push(1);
        else if(s[i] == '[') st.push(2);
        else if(s[i] == '{') st.push(3);
        else {
            if(s[i] == ')') {
                if(!st.empty() && st.top() == 1) st.pop();
                else return 0;
            }
            else if(s[i] == ']') {
                if(!st.empty() && st.top() == 2) st.pop();
                else return 0;
            }
            else if(s[i] == '}') {
                if(!st.empty() && st.top() == 3) st.pop();
                else return 0;
            }
        }
    }
    if(st.empty()) return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO")   << '\n';
    }
    return 0;
}