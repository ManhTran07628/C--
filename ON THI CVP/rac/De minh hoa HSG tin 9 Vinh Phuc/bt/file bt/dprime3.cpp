#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+1;
ll f[N];
vector<ll> a;

ll ktsnt(ll k)
{
    if(k < 2) return 0;
    for(int j = 2;j <= sqrt(k);j++) 
        if(k % j == 0) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "dprime3"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 2;i <= N;i++) f[i] = 1;
    f[1] = f[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
            for(ll j = i*i;j <= N;j+=i)
                f[j] = 0;
    for(int i = 1;i < N;i++) 
        if(f[i]) a.push_back(i);
    ll n;
    cin >> n;
    bool kt = false;
    for(int i = 0;i < a.size()&& a[i]*a[i] <= n;i++) {
        for(int j = i+1;j < a.size() && a[i]*a[i]+a[j]*a[j] <= n;j++) {
            if(ktsnt(a[i]*a[i]+a[j]*a[j]) == 1) {
                cout << a[i] << " " << a[j] << " " << a[i]*a[i]+a[j]*a[j] << '\n';
                kt = true;
            } 
        }
    }
    if(kt == false) cout << -1;
    return 0;
}
