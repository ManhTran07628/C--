#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAKE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll L;
    ll n,dukien = -1e9,thucte = -1e9,vt1 = 0,vt2 = 0;
    cin >> L >> n;
    for(int i = 1;i <= n;i++) {
        ll p,k,ans = 0;
        cin >> p >> k;
        for(int j = p;j <= k;j++) {
            if(a[j] == 0) {
                a[j] = 1;
                ans++;
            }
        }
        if(dukien < k - p + 1) {
            vt1 = i;
            dukien = k - p + 1;
        }
        if(thucte < ans) {
            vt2 = i;
            thucte = ans;
        }
    }
    cout << vt1 << '\n' << vt2;
    return 0;
}