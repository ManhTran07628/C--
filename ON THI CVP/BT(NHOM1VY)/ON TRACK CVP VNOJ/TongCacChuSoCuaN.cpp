#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll ans = 0;
        for(char i:s) ans += i - '0';
        cout << ans << '\n';
    }
    return 0;
}