#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e3+7;
int n,m,a[MM][MM],h[MM][MM],L[MM][MM],R[MM][MM];


void process(int x)
{
    stack<int> st;
    st.push(0);
    for(int i = 1;i <= m;i++) {
        if(a[x][i] == 0) {
            st.push(i);
            continue;
        }
        while(!st.empty() && a[x][i] == a[x][ st.top() ]) st.pop();
        L[x][i] = st.top();
        st.push(i);

        // cout << L[x][i] << ' ';
    }
    while(!st.empty()) st.pop();
    
    st.push(m+1);
    for(int i = m;i >= 1;i--) {
        if(a[x][i] == 0) {
            st.push(i);
            continue;
        }
        while(!st.empty() && a[x][i] == a[x][ st.top() ]) st.pop();
        R[x][i] = st.top();
        st.push(i);

        // cout << R[x][i] << ' ';
    }
    

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    process(10);
    for(int i = 1;i <= n;i++) {
        process(i);
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) h[i][j] = 1;
            if(a[i-1][j]) h[i][j] += h[i-1][j];

            if(a[i-1][j]) {
                L[i][j] = max(L[i][j],L[i-1][j]);
                R[i][j] = min(R[i][j],R[i-1][j]);
            }
        } 
    }

    // for(int j = 1;j <= m;j++)
    //     cout << 5 << ' ' << j << ' ' << L[5][j] << ' ' << R[5][j] << ' ' << h[5][j] << '\n';

    int res = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            res = max(res, (R[i][j] - L[i][j] - 1) * h[i][j]);
        }

    cout << res;
    return 0;
}