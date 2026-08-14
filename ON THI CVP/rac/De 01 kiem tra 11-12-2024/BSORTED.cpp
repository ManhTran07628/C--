#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
ll n;
void solve()
{
    sort(b+1,b+n+1);
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main()
{
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        solve();
    }
    return 0;
}
