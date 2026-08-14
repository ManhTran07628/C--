#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+3;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MAGIC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,x;
        cin >> n >> x;
        if(n >= N) {
            cout << 0;
            continue;
        }
        ll kq = 1;
        for(int i = 1;i <= n;i++) {
            kq = ((x % N) * (i % N)) % N;
        }
        cout << kq;
        cout << '\n';
    }
    return 0;
}