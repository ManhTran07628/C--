#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    while(n >= 2) {
        n /= 2;
        cnt++;
    }
    cout << (1 << cnt);
    return 0;
}