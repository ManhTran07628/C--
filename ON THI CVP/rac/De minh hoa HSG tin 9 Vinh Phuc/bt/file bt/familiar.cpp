#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N],c[N];

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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    for(int i = 1;i <= n;i++) {
        b[i] = max(b[i-1],a[i]+i);
        cout << b[i] << " ";
    }
    cout << '\n';
    for(int i = n;i >= 1;i--) {
        c[i] = max(c[i+1],a[i]+i);
        cout << c[i] << " ";
    }
    cout << '\n';
    return 0;
}