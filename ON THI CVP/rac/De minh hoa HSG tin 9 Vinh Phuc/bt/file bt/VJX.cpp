#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    ll n;
    cin >> n;
    ll soam = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] <= 0) soam++;
    }
    ll tien = 0;
    if(soam % 2 == 0) {
        for(int i = 1;i <= n;i++) {
            if(a[i] < 0) {
                tien += abs(a[i])-1;
            }
            else if(a[i] == 0) {
                tien++;
            }
            else if(a[i] > 0) {
                tien = a[i]-1;
            }
        }
    }
    ll tien1 = 0;
    else if(soam % 2 == 0) {
        ll max1 = -1e9;
        for(int i = 1;i <= n;i++) {
            if(a[i] < 0) {
                tien += abs(a[i])-1;
            }
            else if(a[i] == 0) {
                tien++;
            }
            else if(a[i] > 0) {
                tien = a[i]-1;
            }
        }
    }
    return 0;
}