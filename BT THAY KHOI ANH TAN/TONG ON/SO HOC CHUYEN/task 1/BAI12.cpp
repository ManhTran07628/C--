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
    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if((a+b+c) % 9 == 0 && (a+b+c)/9 <= min({a,b,c})) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}