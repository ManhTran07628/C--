#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "COST"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,a1,b;
    cin >> n >> a1 >> b;
    ll tong = 0;
    ll min1 = min(a1,b);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == 2) {
            tong += a1 + b;
        }
        else tong += min1;
    }
    cout << tong;
    return 0;
}