#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll maxn = -1e9;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    ll max1 = -1e9;
    for(int i = 0;i < maxn*2;i++) {
        ll dem = 0;
        for(int j = 0;j < n;j++) {
            dem += (i % a[j]);
        }
        max1 = max(max1,dem);
    }
    cout << max1;
    return 0;
}
