#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(m == 1) {
        cout << 0;
        return 0;
    }
    sort(a+1,a+n+1,greater<ll>());
    ll s = 1,cnt = 0;
    for(int i = 1;i <= n;i++) {
        s += a[i] - 1;
        cnt++; 
        if(s >= m) {
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
    return 0;
}