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
    int n,cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        int p = sqrt(a);
        if(p*p == a) cnt++;
    }
    cout << cnt;
    return 0;
}