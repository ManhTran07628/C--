#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "8DIVISIBLE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string n;
    cin >> n;
    ll m = n.size();
    for(int i = 0;i < n.size();i++) {
        a[i] = n[i] - '0';
    }
    ll kq = 1e9;
    if(m == 1) {
        if(a[0] % 8 == 0) {
            cout << a[0];
        }
        else {
            cout << -1;
        }
        return 0;
    }
    else if(m == 2) {
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < m;j++) {
                if(a[i] != a[j]) {
                    ll ans = a[i] * 10 + a[j] * 1;
                    if(ans % 8 == 0) {
                        kq = min(kq,ans);
                    }
                }
            }
        }
    }
    else if(m == 3) {
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < m;j++) {
                for(int h = 0;h < m;h++) {
                    if(a[i] != a[j] && a[j] != a[h] && a[h] != a[i]) {
                        ll ans = a[i] * 100 + a[j] * 10 + a[h];
                        if(ans % 8 == 0) {
                            kq = min(kq,ans);
                        }
                    }
                }
            }
        }
    }
    if(kq != 1e9) {
        cout << kq;
    }
    else {
        cout << -1;
    }
    return 0;
}



