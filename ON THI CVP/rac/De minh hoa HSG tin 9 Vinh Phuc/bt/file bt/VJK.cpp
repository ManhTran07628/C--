#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
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
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0;i < n;i++) { // 96
        a[i+1] = a[i] + (s[i]-96);
    }
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}