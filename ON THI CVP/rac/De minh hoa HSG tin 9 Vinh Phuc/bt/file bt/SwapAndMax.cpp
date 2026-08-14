#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SwapAndMax"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        ll l = 1, r = n;
        ll kq = 0;
        while(l <= r) {
            if(l != r) {
                b[kq++]=a[l++];
                b[kq++]=a[r--];
            }
            else b[kq++]=a[r--];
        }
        ll k = 0;
        for(int i = 0;i < n-1;i++) {
            k += abs(b[i]-b[i+1]);
        }
        cout << k + abs(b[n-1]-b[0]) << '\n';

    }
    return 0;
}