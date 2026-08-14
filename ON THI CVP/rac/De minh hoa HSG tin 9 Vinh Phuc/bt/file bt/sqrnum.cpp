#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sqrnum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 2;i <= sqrt(N);i++) { 
        if(f[i] == 0) {
            for(ll j = i*i;j <= N;j+=i) { // tim thua so nguyen to nho nhat cua j
                if(f[j] == 0) {
                    f[j] = i;
                }
            }
        }
    }
    for(int i = 2;i <= N;i++) { // neu i la songuyen to thi chinh no se co somu = 1
        if(f[i] == 0) {
            f[i] = i;
        }
    }
    ll t;
    cin >> t;
    ll exOdd = 0;
    while(t--)
    {
        ll n;
        cin >> n;
        ll primelast = -1;
        ll somu = 0;
        while(n > 1) {
            ll tsntn = f[n];
            if(primelast != tsntn) {
                if(primelast != -1) {
                    if(a[primelast] == 0) {
                        if(somu % 2 != 0) {
                            exOdd++;
                        }
                        a[primelast] = somu;
                    }
                    else {
                        if(a[primelast] % 2 == 0) {
                            if(somu % 2 != 0) {
                                exOdd++;
                            }
                        }
                        else {
                            if(somu % 2 != 0) {
                                exOdd--;
                            }
                        }
                        a[primelast] += somu;
                    }
                    somu = 0;
                }
                primelast = tsntn;
            }
            somu++;
            n /= tsntn;
        }
        if(a[primelast] == 0) {
            if(somu % 2 != 0) {
                exOdd++;
            }
            a[primelast] = somu;
        }
        else {
            if(a[primelast] % 2 == 0) {
                if(somu % 2 != 0) {
                    exOdd++;
                }
            }
            else {
                if(somu % 2 != 0) {
                    exOdd--;
                }
            }
            a[primelast] += somu;
        }
        if(exOdd == 0) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }

    return 0;
}