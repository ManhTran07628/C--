#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
pair<ll,char> a[N];
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
    char k;
    for(int i = 1;i <= 2;i++) {
        cin >> n >> k;
        a[i].first = n;
        a[i].second = k;
    }
    ll k1;
    cin >> k1;
    for(ll i = 1;i <= 2;i++) {
        if(a[i].second == 'A') {
            cout << min(a[i].first,k1);
            return 0;
        }
        else {
            ll tmp = a[i].first;
            k1 -= tmp;
            if(k1 <= 0) {
                cout << 0;
                return 0;
            }
        }
    }
    return 0;
}