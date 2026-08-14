#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll n,k,S;
ll a[N];
ll b[N];

int main() {
    cin >> n >> k >> S;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll dem = 0;
    for(int L = 1;L <= n;L++) {
        ll R = lower_bound(b+L,b+n+1,b[L-1]+S) - b;
        double tmp = R - L + 1;
        ll vtd = ceil(tmp / k);
        ll vtc = (n - L + 1) / k;
        dem += vtc - vtd + 1;   
    }
    cout << dem;
    return 0;
}


// code huy bao
// #include <bits/stdc++.h>
// using namespace std;
// const long long MAXX = 1e7+5;
// long long a[MAXX],p[MAXX];
// int main() {
//     long long n,s;
//      double k;
//     cin>>n>>k>>s;
//     long long kq = 0;
//     for (long long i = 1; i <= n; ++i){
//         cin >> a[i];
//         p[i] = p[i-1] + a[i];
//     }
//     for (long long l = 1; l <= n; ++l){
//         long long x = p[l-1] + s;
//          long double r = lower_bound (p+l,p+n+1,x)-p;
//          double c = (r-l+1);
//         long long dau = ceil(c/k);
//         long long cuoi = (n-l+1)/k;
//         long long ct =cuoi -dau+ 1;
//         kq += ct;
//     }
//     cout<<kq;
//     return 0;
// }
