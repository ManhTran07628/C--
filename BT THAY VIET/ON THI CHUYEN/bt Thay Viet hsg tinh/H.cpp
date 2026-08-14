#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll C,L,D;
    cin >> C >> L >> D;
    if(L == 0) {
        if(D > C) {
            cout << -1;
            return 0;
        }
        cout << C-(min(C/D,100000ll)*D);
        return 0;
    }
    if(D == 0) {
        if(L > C) {
            cout << -1;
            return 0;
        }
        cout << C-(min(C/L,100000ll)*L);
        return 0;
    }
    ll s = L*2+D*1;
    if(C < s) {
        cout << -1;
        return 0;
    }
    ll min1 = 1e9;
    for(int i = 2;i <= 100000;i++) {
        ll cl = C-(L*i);
        if(cl < D) continue;
        ll j = i-1;
        ll kd = min(cl/D,j);
        min1 = min(min1,C-kd*D-i*L);
    }
    cout << min1;
    return 0;
}