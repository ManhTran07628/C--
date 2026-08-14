#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a;
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
    ll n,m;
    cin >> n >> m;
    while(n--) {
        ll a1;
        cin >> a1;
        a[a1]++;
    }
    while(m--) {
        ll a1;
        cin >> a1;
        a[a1]++;
    }
    ll kq = -1;
    for(auto c:a) {
        if(c.second == 2) {
            cout << c.first << " ";
            kq = 1;
        }
    }
    if(kq == -1)
        cout << kq;
    return 0;
}