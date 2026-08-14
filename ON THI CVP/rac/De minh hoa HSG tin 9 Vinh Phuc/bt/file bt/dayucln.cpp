#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "dayucln"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++) {
            if(i == 1) {
                b[i] = a[i];
                b[i+1] = a[i];
            }
            else {
                b[i] = b[i] / __gcd(b[i],a[i]) * a[i];
                b[i+1] = a[i];
            } 
        }
        for(int i = 1;i <= n+1;i++) {
            cout << b[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}