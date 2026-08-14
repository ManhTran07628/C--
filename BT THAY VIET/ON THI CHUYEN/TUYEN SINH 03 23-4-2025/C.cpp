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
    string n;
    ll k;
    cin >> n >> k;
    ll a = 0;
    for(auto i:n) a += (i-'0');
    a *= k;
    while(a > 9) {
        ll a1 = a,sum = 0;
        while(a1 > 0) {
            sum += (a1 % 10);
            a1 /= 10;
        }
        a = sum;
    }
    cout << a;
    return 0;
}