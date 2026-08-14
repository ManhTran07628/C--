#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHIAQUA"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ans += a[i];
    }
    ans = ans / 2;
    if(ans % 100 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}