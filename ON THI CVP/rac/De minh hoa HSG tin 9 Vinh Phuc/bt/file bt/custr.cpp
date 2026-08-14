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
    string s;
    cin >> s;
    string k = "";
    ll solc = 0,kq = 0,solu = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == 'c' || s[i] == 'u') {
            if(s[i] == 'c') solc++;
            else if(s[i] == 'u') {
                solu++;
                kq += solc;
            }
        }
    }
    if(solc > solu) {
        kq += solc;
    }
    else {
        kq += solu;
    }
    cout << kq;
    return 0;
}
