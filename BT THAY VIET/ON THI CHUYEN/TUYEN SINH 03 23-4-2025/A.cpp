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
        ll n;
        cin >> n;
        ll n1 = n;
        int cnt = 0;
        while(n > 0) {
            int tmp = n % 10;
            if(tmp != 0 && n1 % tmp == 0) cnt++;
            n /= 10;
        }
        cout << cnt << '\n';
    }
    return 0;
}