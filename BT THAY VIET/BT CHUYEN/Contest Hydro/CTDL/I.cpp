#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e6+7;
ll n,a[MM];
stack<int> st;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    a[n+1] = oo;
    st.push(n+1);
    vector<int> pos;
    for(int i = n;i >= 1;i--) {
        while(a[i] >= a[st.top()]) st.pop();
        pos.push_back( (st.top() == n+1 ? 0 : st.top()) );
        st.push(i);
    }
    reverse(pos.begin(),pos.end());
    for(auto i:pos) cout << i << ' ';
    return 0;
}