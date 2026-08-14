#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,a[4][MM],cnt[4][MM],erasedcol[MM];
vector<int> col[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= 3;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            cnt[i][ a[i][j] ]++;
            col[ a[i][j] ].push_back(j);
        }
    }

    stack<int> st;
    for(int v = 1;v <= n;v++) {                                                                                                   
        if(cnt[2][v] == 0 || cnt[3][v] == 0) st.push(v);
    }
    int res = 0;
    while(!st.empty()) {
        int v = st.top(); st.pop();
        for(auto x:col[v]) {
            
            if(erasedcol[x]) continue;
            erasedcol[x] = 1;
            for(int i = 1;i <= 3;i++) {
                int v = a[i][x];
                cnt[i][v]--;
                if(cnt[2][v] == 0 || cnt[3][v] == 0) st.push(v);
            }
            res++;

        }
    }

    cout << res;


    return 0;
}