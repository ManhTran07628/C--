#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int mark[5001],dp[5001];
int MOD = 998244353;
vector<int> a;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q,k;
    cin >> q >> k;
    for(int i = 1;i <= q;i++) {
        char type;
        int x;
        cin >> type >> x;
        if(type == '+') mark[x]++;
        else mark[x]--;
    }
    for(int i = 1;i <= 5000;i++) {
        for(int j = 1;j <= mark[i];j++) {
            a.push_back(i);
        }
    }
    dp[0] = 1;
    for(int i = 0;i < a.size();i++) {
        for(int j = k;j >= a[i];j--) {
            dp[j] = (dp[j-a[i]]+dp[j])%MOD;
        }
    }
    cout << dp[k];
    return 0;
}