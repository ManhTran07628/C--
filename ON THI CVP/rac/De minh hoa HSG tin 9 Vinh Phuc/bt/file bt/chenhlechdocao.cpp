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
    ll max1 = -1e9,min1 = 1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll kq = -1e9;
    for(int i = n;i >= 1;i--) {
        if(a[i] > max1) {
            max1 = a[i];
        }
        kq = max(kq,max1-a[i]);
    }
    cout << kq;
    return 0;
}