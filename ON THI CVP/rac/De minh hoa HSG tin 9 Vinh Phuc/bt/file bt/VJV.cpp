#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll max1 = -1e9;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            max1 = max(max1,a[i]);
        }
        if(max1 == 1) {
            cout << 0 << '\n';
        }
        else {
            cout << max1 << '\n';
        }
    }
    return 0;
}