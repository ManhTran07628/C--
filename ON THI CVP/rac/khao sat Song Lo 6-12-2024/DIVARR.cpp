#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DIVARR"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll cnt = 0;
    for(int i = 1;i < n;i++) {
        if(b[i] == b[n] - b[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
