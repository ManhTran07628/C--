#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,d[MM],w[MM];

stack<int> st;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> d[i] >> w[i];
    }
    w[n+1] = 0;
    int cnt = 0;
    for(int i = 1;i <= n+1;i++) {
        while(!st.empty() && w[i] < w[ st.top() ]) {
            cnt++;
            st.pop();
        }
        if( (!st.empty() && w[ st.top() ] != w[i])
        || (st.empty()) ) st.push(i);
    }
    cout << cnt;
    return 0;
}