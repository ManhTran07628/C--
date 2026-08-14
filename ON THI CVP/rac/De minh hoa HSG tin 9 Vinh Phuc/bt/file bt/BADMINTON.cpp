#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],c[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BADMINTON"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    sort(c+1,c+n+1);
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        ll ans = upper_bound(c+i,c+n+1,-c[i]) - c;
        if(ans != n+1) {
            if(ans != i) {
                dem += n - ans + 1;
            }
            else {
                dem += n - ans;
            }
        }
    }
    cout << dem;
    return 0;
}
// 6
// 3 8 2 6 2 7
// 4 5 4 1 3 9
// binary - 9
// brute force -  9
// ll dem = 0;
// for(int i = 1;i <= n;i++) {
//     for(int j = i+1;j <= n;j++) {
//         if(a[i] + a[j] > b[i] + b[j]) {
//             dem++;
//         }
//     }
// }
// cout << dem;