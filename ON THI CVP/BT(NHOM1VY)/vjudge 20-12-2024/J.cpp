#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1000+7;
ll b[N][N],ans = 0;
ll m,n;
ll solve(ll x)
{
    stack<ll> st;
    ll l[n+6],r[n+6],a[n+6];
    for(int i = 1;i <= n;i++) {
        a[i] = b[x][i];
    }
    a[0] = -1;
    st.push(0);
    for(int i = 1;i <= n;i++) {
        while(a[st.top()] >= a[i]) st.pop();
        l[i] = st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    a[n+1] = -1;
    st.push(n+1);
    for(int i = n;i >= 1;i--) {
        while(a[st.top()] >= a[i]) st.pop();
        r[i] = st.top()-1;
        st.push(i);
    }
    ll tmp = 0;
    for(int i = 1;i <= n;i++) {
        ll s = (r[i]-l[i]+1)*a[i];
        tmp = max(tmp,s);
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> b[i][j];
        }
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(b[i][j] != 0) b[i][j] += b[i-1][j];
        }
    }
    for(int i = 1;i <= m;i++) {
        ans = max(ans,solve(i));
    }
    cout << ans;
    return 0;
}