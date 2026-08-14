#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "schedule"
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
        if(x > 10) {
            cout << 0 << '\n';
            continue;
        }
        ll kq = (10-x)*(n-1);
        cout << kq << '\n';
    }
    return 0;
}