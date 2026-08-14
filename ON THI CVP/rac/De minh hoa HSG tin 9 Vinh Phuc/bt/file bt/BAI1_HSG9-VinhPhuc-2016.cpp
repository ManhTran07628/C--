#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "buymilk"
    if (fopen(taskname ".inp", "r")) {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    ll A, B, C, D;
    ll tong = 0; 
    cin >> A >> B >> C >> D; 

    if (A < B && A < C) {
        cout << 0; 
        return 0;
    } 

    ll suahop = A / B;
    ll tienthua = A - (suahop * B); 
    ll suabinh = tienthua / C; 
    tong = max(tong, suahop + suabinh); 



    ll suabinh2 = A / C; 
    tienthua = A - (suabinh2 * C); 
    ll suahop2 = tienthua / B;
    tong = max(tong, suabinh2 + suahop2); 

    cout << tong; 
    return 0;
}
