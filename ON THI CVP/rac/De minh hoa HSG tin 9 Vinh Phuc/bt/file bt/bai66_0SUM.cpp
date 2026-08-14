#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "0-SUM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll chiso = -1;
    for(int i = 1;i <= n;i++) {
        ll ans = b[n] - b[i] + (a[i] * -1) + b[i-1] - b[0];
        if(ans == 0) {
            chiso = i;
            break;
        }
    }
    cout << chiso;
    return 0;
}



