#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

ll phantich(ll k)
{
    ll k1 = k,tongcs = 0,tongts = 0;
    while(k1 > 0) {
        tongcs += k1 % 10;
        k1 /= 10;
    }
    for(int i = 2;i <= sqrt(k);i++) {
        while(k % i == 0) {
            tongts += i;
        }
    }
    if(k > 1) tongts += k;
    if(tongcs == tongts) {
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sodb"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    while(n++) {
        if(phantich(n) == 1) {
            cout << n;
            return 0;
        }
    }
    return 0;
}