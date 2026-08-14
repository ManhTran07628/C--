#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int mm = 1e9;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
        mm = min(a[i],mm);
    }
    for(int i = mm;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(i - a[j] >= 0 && dp[i-a[j]] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    if(dp[n]) cout << "Marisa";
    else cout << "Reimu";
    return 0;
}