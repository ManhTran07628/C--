#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int t = 1e5;
int main()
{
    for(ll i = 2;i <= t;i++) {
        a[i] = 1;
    }
    for(ll i = 2;i <= t;i++) {
        if(a[i] == 1) {
            for(ll j = i*i;j <= t;j = j + i) {
                if(a[j] == 1) {
                    a[j] = 0;
                    b[i]++;
                }
            }
        }
    }
    ll n,x;
    cin >> n;
    while(n--) {
        cin >> x;
        if(x > 1e5) {
            cout << 0 << endl;
            continue;
        }
        cout << b[x]+1 << endl;
    }
    return 0;
}
