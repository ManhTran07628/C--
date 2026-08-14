#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
unordered_map<ll,ll> b;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ANTAG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    sort(a+1,a+n+1);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        if(k != 0)
            ans += b[a[i]+k];
        else {
            ans += (b[a[i]] * (b[a[i]]-1)) / 2;
            b[a[i]] = 0;
        }
    }
    cout << ans;
    return 0;
}