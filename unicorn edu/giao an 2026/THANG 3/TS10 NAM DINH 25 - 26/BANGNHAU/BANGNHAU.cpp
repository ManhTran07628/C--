#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BANGNHAU"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int S = a + b + c + d;

    if (S % 2 != 0) {
        cout << "KHONG";
    } else {
        int t = S / 2;

        if (a == t || b == t || c == t || d == t ||
            a + b == t || a + c == t || a + d == t ||
            b + c == t || b + d == t ||
            c + d == t) {
            cout << "CO";
        } else {
            cout << "KHONG";
        }
    }
    return 0;
}