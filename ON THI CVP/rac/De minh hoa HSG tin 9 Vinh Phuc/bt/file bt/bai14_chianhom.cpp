#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 101;
ll a[N][N];
vector<ll> b,c;
int main() {
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            if(a[i][j] == 0 && i == 1) {
                b.push_back(j);
            }
            if(a[i][j] == 0 && i == 2) {
                b.push_back(j);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        int vt = 1;
        for(int j = 1;j <= n;j++) {
            if(a[i][j] == b[vt]) {

            }
        }
    }
    return 0;
}



