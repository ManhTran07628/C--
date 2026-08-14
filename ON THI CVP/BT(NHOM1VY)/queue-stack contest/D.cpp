#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
multiset<ll> ms;
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
    while(t--) {
        ll n,k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for(int i = 1,j = 1;j <= n;j++) {
            ms.insert(a[j]);
            if(j-i+1 == k) {
                cout << *ms.begin() << ' ';
                ms.erase(ms.find(a[i]));
                i++;
            }
        }
        ms.clear();
        cout << '\n';
    }
    return 0;
}