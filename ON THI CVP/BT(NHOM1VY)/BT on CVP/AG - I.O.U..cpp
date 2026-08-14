#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int d[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        d[a] -= c;
        d[b] += c;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) 
        if(d[i] > 0) ans += d[i];
    cout << ans;
    return 0;
}