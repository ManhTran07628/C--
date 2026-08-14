#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll f[N],t[N],r[N];
vector<ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TICK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> t[i];
    }
    for(int i = 1;i < n;i++) {
        cin >> r[i];
    }
    f[1] = t[1];
    f[2] = min(f[1]+t[2],r[1]);
    for(int i = 3;i <= n;i++) {
        f[i] = min(f[i-1]+t[i],f[i-2]+r[i-1]);
    }
    cout << f[n] << '\n';
    ll i = n;
    while(i >= 1) {
        if(f[i] == f[i-1]+t[i]) {
            i--;
        }
        else if(f[i] == f[i-2]+r[i-1]) {
            a.push_back(i);
            i -= 2;
        }
    }
    reverse(a.begin(),a.end());
    for(auto c:a) {
        cout << c << " ";
    }
    return 0;
}
