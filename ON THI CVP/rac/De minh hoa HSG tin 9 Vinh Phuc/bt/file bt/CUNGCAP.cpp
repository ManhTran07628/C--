#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
ll tmp = 1e7;

bool ktsnt(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++){
        if(k % i == 0) return 0;
    }
    return 1;
}
ll tongchuso(ll k){
    ll tong = 0;
    while(k > 0) {
        ll tmp = k % 10;
        tong += tmp * tmp;
        k /= 10;
    }
    return tong;
}
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
    ll n;
    cin >> n;
    ll i = n;
    while(i > 0) {
        if(ktsnt(tongchuso(i))) {
            cout << i;
            return 0;
        }
        i--;
    }
    cout << 0;
    return 0;
}
