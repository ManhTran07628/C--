#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pb pop_back

const int N = 2e6 + 7;
ll a[N];
int main()
{
    ll n,q;
    cin >> n >> q;
    while(q--) {
        ll l,r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    for(int i = 0;i < n;i++) {
        a[i+1] = a[i] + a[i+1];
        cout << a[i+1] << " ";
    }
    return 0;
}
