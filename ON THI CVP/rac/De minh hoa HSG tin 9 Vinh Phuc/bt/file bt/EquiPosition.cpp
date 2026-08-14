#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "EquiPosition"
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
            b[i] = b[i-1] + a[i];
        }
        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }
        ll cs = -1;
        for(int i = 1;i <= n;i++) {
            ll dau = b[i];
            ll cuoi = b[n]-b[i-1];
            if(dau == cuoi) {
                cs = i;
                break;
            }
        }
        cout << cs << '\n';
    }
    return 0;
}   