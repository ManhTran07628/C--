#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<ll> a;
int main()
{
    ll t;
    cin >> t;
    while(t > 1) {
        ll tmp = 2;
        if(t % tmp == 0) {
            a.push_back(tmp);
            t /= tmp;
        }
        else {
            while(true) {
                if(t % tmp == 0) {
                    a.push_back(tmp);
                    t /= tmp;
                    break;
                }
                else {
                    tmp++;
                }
            }
        }
    }
    sort(a.begin(),a.end());
    for(ll c : a) {
        cout << c;
    }
    return 0;
}

