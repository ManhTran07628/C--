#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<ll> a;
ll b[N];
int main() {
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        ll a1;
        cin >> a1;
        if(b[a1] == 0) {
            a.push_back(a1);
            b[a1]++;
        }
    }
    sort(a.begin(),a.end(),greater<ll>());
    for(auto c : a) {
        cout << c << " ";
    }
    return 0;
}


