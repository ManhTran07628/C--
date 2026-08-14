#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ANT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,L,cuoi = -1e9;
    cin >> n >> L;
    for(int i = 1;i <= n;i++) {
        ll x;
        string y;
        cin >> x >> y;
        cuoi = max(cuoi,L-x);
    }
    cout << cuoi;
    return 0;
}