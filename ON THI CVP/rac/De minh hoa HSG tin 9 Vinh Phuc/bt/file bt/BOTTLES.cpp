#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N];
vector<ll> b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BOTTLES"
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
    f[1] = a[1];
    f[2] = a[1]+a[2];
    f[3] = max({f[2],f[0]+a[3],f[2]-a[1]+a[3]});
    for(int i = 4;i <= n;i++) {
        f[i] = max({f[i-1],f[i-2]+a[i],f[i-3]+a[i-1]+a[i]});
        //cout << f[i] << " ";
    }
    ll i = n;
    while(i >= 1) {
        if(f[i] == f[i-1]) {
            i--;
        }
        else if(f[i] == f[i-2] + a[i]) {
            b.push_back(i);
            i -= 2;
        }
        else if(f[i] == f[i-3] + a[i-1] + a[i]) {
            b.push_back(i);
            b.push_back(i-1);
            i -= 3;
        }
    }
    cout << b.size() << " " << f[n] << '\n';
    for(auto c:b) cout << c << '\n';
    //cout << f[n];
    return 0;
}