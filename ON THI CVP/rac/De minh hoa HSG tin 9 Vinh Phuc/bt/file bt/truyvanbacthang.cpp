#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pb pop_back

const int N = 2e6 + 7;
ll a[N],b[N],c[N];
int main()
{
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + (a[i]*i);// kq
        c[i] = c[i-1] + a[i];//prefix sum
    }
    for(int i = 1;i <= q;i++) {
        ll l,r;
        cin >> l >> r;
        cout << b[r] - b[l-1] - (l - 1) * (c[r] - c[l - 1])<< endl;
    }
    return 0;
}
