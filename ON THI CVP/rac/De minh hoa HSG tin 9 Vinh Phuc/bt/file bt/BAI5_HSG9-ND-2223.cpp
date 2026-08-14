#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
ll a[N];
map<ll,ll> c;
ll tmp = 1e6;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TBZ"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    c[0] = 1;
    ll dem = 0;
    ll tongtt = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tongtt += a[i];
        dem += c[tongtt];
        c[tongtt]++;
    }
    cout << dem;
    return 0;
}