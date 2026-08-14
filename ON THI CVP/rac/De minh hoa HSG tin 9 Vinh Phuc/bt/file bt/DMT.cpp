#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> f;
bool a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DMT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    for(int i = 2;i < N;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i*i <= N;i++) 
        if(a[i])
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
    for(int i = 1;i < N;i++) {
        if(a[i]) f.push_back(i);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll a1,b;
        cin >> a1 >> b;
        ll c = ceil(sqrt(ceil(a1/9.0)));
        ll i = lower_bound(f.begin(),f.end(),c) - f.begin();
        ll d = sqrt(b/9);
        ll j = upper_bound(f.begin(),f.end(),d) - f.begin();
        cout << j - i - (f[i] >= 3 && f[j] < 3) + (a1 <= 6561 && b >= 6561) << '\n';
    }
    return 0;
}
// 36
// 225
// 441
// 1089
// 1521
// 2601
// 3249
// 4761
// 6561
// 7569
// 8649