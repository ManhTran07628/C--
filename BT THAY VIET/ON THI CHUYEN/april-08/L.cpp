#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[101],b[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ans += max(a[i],b[j])*(a[i]+b[j]);
        }
    }
    cout << ans;
    return 0;
}