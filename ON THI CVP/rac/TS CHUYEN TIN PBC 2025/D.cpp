#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
stack<int> st;
int a[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    st.push(0);
    a[0] = 1e18;
    for(int i = 1;i <= n;i++) {
        while(a[i] >=  a[st.top()]) st.pop();
        cout << i-st.top()-1 << ' ';
        st.push(i);
    }
    return 0;
}