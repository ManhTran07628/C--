#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "XOASO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string n;
    int k;
    cin >> n >> k;
    int lim = n.size();
    n = ' ' + n;
    
    stack<int> st;
    for(int i = 1;i <= lim;i++) {
        while(!st.empty() && k > 0 && (n[i] - '0') > st.top()) {
            k--;
            st.pop();
        }
        st.push(n[i] - '0');
    }
    while(k > 0) {
        st.pop();
        k--;
    }
    string ans;
    while(!st.empty()) {
        ans = ans + char(st.top() + '0');
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}