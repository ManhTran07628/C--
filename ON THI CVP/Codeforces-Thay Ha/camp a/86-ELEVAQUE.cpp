#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int ans = 1,pr = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(pr + a[i] <= m) pr += a[i];
        else {
            pr = a[i];
            ans++;
            
        }
    }
    cout << ans;
    return 0;
}