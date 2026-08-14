#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 51 + 7;
vector<vector<int>> a,b;
int n,q;
ll dp[5][MM][MM];

vector<vector<int>> rorateRight(vector<vector<int>> x)
{
    vector<vector<int>> y = x;
    for(int i = 1;i <= n;i++) {
        int k = 1;
        for(int j = n;j >= 1;j--,k++) {
            y[i][j] = x[k][i];
        }
    }
    return y;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "CROMAT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }

    cin >> n >> q;
    a.resize(n+1);
    for(int i = 1;i <= n;i++) {
        a[i].push_back(0);
        for(int j = 1;j <= n;j++) {
            int c; cin >> c;
            a[i].push_back(c);
        }
    }
    

    for(int state = 1;state <= 4;state++) {

        for(int i = 1;i <= n;i++) 
            for(int j = 1;j <= n;j++) 
                dp[state][i][j] = oo;


    }
    
    for(int state = 0;state < 4;state++) {

        for(int i = 1;i <= n;i++) 
            dp[state][i][1] = a[i][1];

        for(int j = 2;j <= n;j++) 
            for(int i = 1;i <= n;i++) {
                dp[state][i][j] = max({dp[state][i][j-1],
                    dp[state][i-1][j-1],
                    dp[state][i+1][j-1]}) + a[i][j];
            }

        a = rorateRight(a);
    }

    int cur_state = 0;
    while(q--) {
        char type; cin >> type;
        if(type == 'R') {
            int x; cin >> x;
            x %= 4;
            cur_state = (cur_state + x) % 4;
        }
        else if(type == 'L') {
            int x; cin >> x;
            x %= 4; x = 4 - x;
            cur_state = (cur_state + x) % 4;
        }
        else {
            int k; cin >> k;
            ll max_res = -oo;
            for(int i = 1;i <= n;i++) {
                max_res = max(max_res,dp[cur_state][i][n]);
            }
            cout << max_res << '\n';
        }
    }
    return 0;
}