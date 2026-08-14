#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
map<ll,ll> b;
ll tmp = 0;
int main()
{
    ll x,y;
    cin >> x >> y;
    string s;
    cin >> s;
    b[0] = 1;
    ll kq = 0,d1 = 0,d2 = 0;//d1 sol so 0 d2 sol so 1
    for(ll i = 0;i < s.size();i++) {
        if(s[i] == '0') {
            d1++;
        }
        else if(s[i] == '1'){
            d2++;
        }
        kq += b[d1*y-d2*x];
        b[d1*y-d2*x]++;
    }
    cout << kq;
    return 0;
}
