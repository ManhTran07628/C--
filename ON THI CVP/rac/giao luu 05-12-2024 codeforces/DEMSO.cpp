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
    ll n,k,d;
    cin >> n >> k >> d;
    if(k % d == 0) {
        cout << n;
        return 0;
    }
    ll cnt = 0;
    if(d == 6) {
        if(k % 2 == 0) {
            cnt = n / 3;
        }
        else if(k % 3 == 0) {
            cnt = n / 2;
        }
        else cnt = n / 6;
    }
    else cnt = n / d;
    cout << cnt;
    return 0;
}