#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

void solve()
{
    for(int i = 1;i <= N;i++) {
        for(int j = i;j <= N;j+=i) {
            a[j]++;
        }
    }
    for(int i = 1;i <= N;i++) {
        a[i] += a[i-1];
    }
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
    solve();
    ll q;
    cin >> q;
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}