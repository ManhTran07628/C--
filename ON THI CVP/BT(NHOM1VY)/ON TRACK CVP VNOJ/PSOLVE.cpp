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
    ll n,d;
    ll max1 = 0,min1 = 1e10;
    cin >> n >> d;
    for(int i = 1;i <= n;i++) {
        ll a;
        cin >> a;
        max1 = max(max1,a);
        min1 = min(min1,a);
        if(max1 - min1 >= d) {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}