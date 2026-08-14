#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[71][70001],a[1001];
map<int,int> lt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        m+=a[i];
    }
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= a[i];j--) {
            if(dp[i][j])
        }
    }
    return 0;
}