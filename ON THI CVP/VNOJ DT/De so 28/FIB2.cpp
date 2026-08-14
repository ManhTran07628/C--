#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
string a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "FIB2"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    a[0] = "a";
    a[1] = "b";
    for(int i = 2;i <= 41;i++) {
        a[i] = a[i-2] + a[i-1];
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        ll cnt = 0;
        for(int i = 0;i <= k;i++) {
            if(a[n][i] == 'a') cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}