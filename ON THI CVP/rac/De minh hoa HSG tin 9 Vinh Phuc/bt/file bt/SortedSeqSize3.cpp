#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],l[N],r[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SortedSeqSize3"
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
        ll max1 = 0;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
        }
        l[0] = a[0];
        for(int i = 1;i < n;i++) {
            l[i] = min(l[i-1],a[i]);
        }
        r[n-1] = a[n-1];
        for(int i = n-2;i >= 0;i--) {
            r[i] = max(r[i+1],a[i]);
        }
        ll kt = 0;
        for(int i = 1;i < n-1;i++) {
            if(a[i] > l[i-1] && r[i+1] > a[i]) {
                kt = 1;
                break;
            }
        }
        if(kt) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}