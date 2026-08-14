#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "dice"
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
        if(n == 6) cout << 1;
        if(n == 5) cout << 2;
        if(n == 4) cout << 3;
        if(n == 3) cout << 4;
        if(n == 2) cout << 5;
        if(n == 1) cout << 6;
        cout << '\n';
    }
    return 0;
}