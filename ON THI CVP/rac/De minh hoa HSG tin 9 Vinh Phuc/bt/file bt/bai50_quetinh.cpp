#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
stack<ll> a;
int main() {
    freopen("SIBICE.inp","r",stdin);
    freopen("SIBICE.out","w",stdout);
    ll n,w,h;
    cin >> n >> w >> h;
    ll dodai = floor(sqrt(w*w+h*h));
    while(n--) {
        ll b;
        cin >> b;
        if(b <= dodai) {
            cout << "DA" << endl;
        }
        else {
            cout << "NE" << endl;
        }
    }
    return 0;
}
// floor lam tron xuong
// ceil lam tron len


