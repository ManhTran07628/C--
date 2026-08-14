#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[101][101];
int main() {
    ll n;
    cin >> n;
    ll d = n;
    for(int i = 1;i <= n;i++) {
        if(i == 1) {
            for(int j = 1;j <= n;j++) {
                cout << j << " ";
            }
            cout << endl;
            continue;
        }
        for(int j = 1;j <= n;j++) {
            if(i % 2 != 0) {
                cout << d*(i-1)+j << " ";
            }
            else if(i % 2 == 0) {
                cout <<  d*i-j+1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

