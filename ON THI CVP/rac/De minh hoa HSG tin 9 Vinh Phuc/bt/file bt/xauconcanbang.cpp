#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
map<ll,ll> b;
ll tmp = 0;
int main()
{
    string s;
    cin >> s;
    b[0] = 1;
    ll kq = 0;
    for(ll i = 0;i < s.size();i++) {
        if(s[i] == '1') {
            tmp++;
        }
        else if(s[i] == '0'){
            tmp--;
        }
        kq += b[tmp];
        b[tmp]++;
    }
    cout << kq;
    return 0;
}
