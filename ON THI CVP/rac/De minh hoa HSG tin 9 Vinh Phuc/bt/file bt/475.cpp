#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
multiset<ll> a;
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
    ll q;
    cin >> q;
    while(q--) {
        ll n,x;
        cin >> n >> x;
        if(n == 1) {
            a.insert(x);
        }
        else if(n == 2) {
            auto it = a.find(x);
            if(it != a.end()) {
                a.erase(it);
            }
        }
        else if(n == 3) {
            auto it = a.upper_bound(x);
            if(it != a.end()) {
                cout << *it << '\n';
            }
            else cout << -1 << '\n';
        }
        else if(n == 4) {
            auto it = a.lower_bound(x);
            if(*it > x || it == a.end()) {
                if(it == a.begin()) {
                    cout << -1 << '\n';
                }
                else cout << *(--it) << '\n';
            } 
            else {
                cout << *it << "\n";
            }
        }
    }
    return 0;
}