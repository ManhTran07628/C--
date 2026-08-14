#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SmithNum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll k;
        cin >> k;
        ll kt = 0;
        for(int i = 2;i <= sqrt(k);i++) {
            if(k % i == 0) kt = 1;
        }
        if(kt == 0) {
            cout << 0 << '\n';
            continue;
        }
        ll k1 = k,tong = 0,tongcs = 0;
        while(k1 > 0) {
            tong += k1 % 10;
            k1 /= 10;
        }
        for(int i = 2;i <= sqrt(k);i++) {
            while(k % i == 0) {
                ll tmp = 0;
                ll i1 = i;
                while(i1 > 0) {
                    tmp += i1 % 10;
                    i1 /= 10;
                }
                tongcs += tmp;
                k/=i;
            }
        }
        if(k > 1) {
            ll tmp = 0;
            ll i1 = k;
            while(i1 > 0) {
                tmp += i1 % 10;
                i1 /= 10;
            }
            tongcs += tmp;
        }
        if(tong == tongcs) {
            cout << 1 << '\n';
        }
        else cout << 0 << '\n';
    }
    return 0;   
}