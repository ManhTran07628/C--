#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;
int main()
{
    ll n;
    cin >> n;
    string k = "";
    if(n < 10) {
        cout << n;
        return 0;
    }
    while(n > 0) {
        if(n >= 9) {
            k += '9';
            n -= 9;
        }
        else {
            char tmp = (char)(n + '0');
            k += tmp;
            break;
        }
    }
    reverse(k.begin(),k.end());
    cout << k;
    return 0;
}

