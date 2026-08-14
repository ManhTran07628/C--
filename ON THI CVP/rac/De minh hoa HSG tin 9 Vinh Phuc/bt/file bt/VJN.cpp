#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
set<ll> f;
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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        ll dem = 0;
        for(int i = 1;i <= n;i++) {
            if(f.find(a[i]) != f.end()) 
                f.insert(a[i]+1);
            else f.insert(a[i]);
        }
        cout << f.size() << '\n';
        f.clear();
    }
    return 0;
}