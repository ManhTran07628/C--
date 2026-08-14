#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

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
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll k;
    cin >> k;
    ll vtd = lower_bound(a+1,a+n+1,k)- a;
    ll vtc = upper_bound(a+1,a+n+1,k) - a;
    if(vtd == n+1 && vtc == n+1 && b[k] == 0) {
        cout << -1 << " " << -1 << " " << 0;
        return 0;
    }
    cout << vtd << " " << vtc << " " << b[k];
    return 0;
}