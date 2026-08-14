#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ALTB"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    ll mina = 1e9,minb = 0;
    for(ll i = 1;i <= k-1;i++) {
        ll vt1 = 0,vt2 = 0;
        for(ll j = 1;i + j<= k;j++) {
            if(i + j == k) {
                if(pow(i,j-1) == n/i) {
                    vt1 = i, vt2 = j;
                }
            }
        }
        if(vt1 != 0 && vt2 != 0 && vt1 < mina) {
            mina = vt1,minb = vt2;
        }
    }
    if(minb == 0) {
        cout << -1;
        return 0;
    }
    cout << mina << " " << minb;
    return 0;
}