#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];


bool ktsnt(ll k) {
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++)
        if(k % i == 0) return 0;
    return 1;
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
    ll a1,b,k,s;
    cin >> a1 >> b >> k >> s;
    for(ll i = a1;i <= b;i++) {
        a[i-a1+1] = ktsnt(i);
    }
    ll dem1 = 0;
    for(ll i = a1;i <= b;i++) {
        if(a[i-a1+1] == 1) {
            ll dem = 0;
            ll kc = 0;
            for(ll j = i;j <= b;j++) {
                if(a[j-a1+1] == 1) {
                    dem++;
                    kc = j;
                    if(dem == k) {
                        break;
                    }
                }
            }
            if(dem == k) {
                if(kc - i == s) dem1++;
            }
        }
    }
    cout << dem1;
    return 0;
}