#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
vector<ll> b,c;
int main() {
    freopen("FINDNAME.inp","r",stdin);
    freopen("FINDNAME.out","w",stdout);
    string s;
    cin >> s;
    ll n = s.size();
    for(ll i = 0;i < n;i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
            s.erase(i+1,1);
        }
    }
    cout << s;
    return 0;
}
