#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 31;
int m,n,P[MM],k[MM][MM],dp[60000][31],pow3[MM];

void readinput()
{
    cin >> m >> n;
    for(int i = 1;i <= m;i++) cin >> P[i];
    cin.ignore();
    for(int i = 1;i <= n;i++) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        int food;
        while(ss >> food) {
            k[i][food] = 1;
        }
    }
}

vector<int> tam_phan(int mask)
{
    vector<int> v;
    for(int i = n-1;i >= 0;i--) {
        int cur_m = mask / pow3[i];
        v.push_back(cur_m);
        mask -= cur_m * pow3[i];
    }
    return v;
}

int thap_phan(vector<int> t)
{
    int ans = 0;
    for(int i = n-1;i >= 0;i--) {
        ans += pow3[i] * t[n - 1 - i];
    }
    return ans;
}

void solve()
{
    pow3[0] = 1;
    for(int i = 1;i <= 17;i++) pow3[i] = pow3[i-1] * 3;
    
    for(int i = 0;i <= m;i++) {
        for(int j = 0;j < pow3[n];j++) {
            dp[j][i] = oo;
        }
    }

    dp[0][0] = 0;
    
    for(int i = 1;i <= m;i++) {
        for(int mask = 0;mask < pow3[n];mask++) {
            vector<int> mask_c = tam_phan(mask);
            dp[mask][i] = dp[mask][i-1];

            bool check = 1;
            for(int j = 0;j < n;j++) {
                if(k[j+1][i]) {
                    if(mask_c[n - 1 - j] == 0) check = 0;
                    mask_c[n - 1 - j]--;
                }
            }

            if(check) {
                dp[mask][i] = min(dp[mask][i],dp[thap_phan(mask_c)][i-1] + P[i]);
            }
        }
    }

    cout << (dp[pow3[n]-1][m] == 1e9 ? -1 : dp[pow3[n]-1][m]);
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    readinput();
    solve();
    return 0;
}