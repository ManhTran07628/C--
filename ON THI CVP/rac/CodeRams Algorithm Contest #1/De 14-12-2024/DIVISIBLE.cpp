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
    #define taskname "DIVISIBLE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        ll cnt = 0;
        for(auto c:n) {
            cnt += (c-'0');
        }
        if(cnt % 9 == 0) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}