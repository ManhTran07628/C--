#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,k;
int a[MM],b[MM];
stack<int> st;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    st.push(n+1);
    a[n+1] = oo;
    for(int i = n;i >= 1;i--) {
        while(a[st.top()] <= a[i]) st.pop();
        b[i] = st.top();
        st.push(i);
    }
    
    return 0;
}