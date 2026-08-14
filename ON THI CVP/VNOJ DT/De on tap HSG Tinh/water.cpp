#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "water"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a == b) {
            cout << 0 << '\n';
            continue;
        }
        if(a < b) swap(a,b);
        int m = a-((a+b)/2);
        int ans = m / c;
        if(m % c != 0) ans++;
        cout << ans << '\n';
    }
    return 0;
}