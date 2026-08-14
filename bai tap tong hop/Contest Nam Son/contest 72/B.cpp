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
        s = xuly(s);
        ll p = stoll(s);
        ll ans = 0,k = 2,i = 1;
        while(k < s.size()) {
            i =  pow(10,k-2)*9;
            ans += i;
            k += 2;
        }
        ans += (p-i)+1;
        cout << ans << '\n';
    }
    return 0;
}