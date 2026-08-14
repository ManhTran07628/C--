#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ull unsigned long long
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll a1 = 1,a2 = 1;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    for(int i = 3;i <= n;i++) {
        ll c = a2;
        a2 = a1+a2;
        a1 = c;
    }
    cout << a2;
    return 0;
}