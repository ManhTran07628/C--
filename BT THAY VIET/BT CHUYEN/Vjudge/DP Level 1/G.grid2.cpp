#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
string dp[105][105];
int a[105][105];

string bignum_plus(string a,string b)
{
    while(a.size() != b.size()) {
        if(a.size() < b.size()) a = '0' + a;
        else b = '0' + b;
    }
    string ans;
    int nho = 0,n = a.size();
    for(int i = n-1;i >= 0;i--) {
        int unit = a[i]-'0'+b[i]-'0'+nho;
        nho = unit / 10;
        char c = (unit%10)+'0';
        ans = ans + c;
    }
    if(nho > 0) ans += '1';
    reverse(ans.begin(),ans.end());
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << bignum_plus("2","9");
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = "1";
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(i+a[i][j] < n && a[i][j] != 0) dp[i+a[i][j]][j] = bignum_plus(dp[i+a[i][j]][j],dp[i][j]);
            if(j+a[i][j] < n && a[i][j] != 0) dp[i][j+a[i][j]] = bignum_plus(dp[i][j+a[i][j]],dp[i][j]);
        }
    }   
    cout << dp[n-1][n-1];
    return 0;
}