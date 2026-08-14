#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
set<ll> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SOANDE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll a1,a2,a3,a4;
        cin >> a1 >> a2 >> a3 >> a4;
        a.insert(a1);
        a.insert(a2);
        a.insert(a3);
        a.insert(a4);
        if(a.size() == 4) {
            cout << 2;
            cout << endl;
            a.clear();
            continue;
        }
        if(a.size() == 3 || a.size() == 2) {
            cout << 1 << endl;
            a.clear();
            continue;
        }
        if(a.size() == 1) {
            cout << 0 << endl;
            a.clear();
            continue;
        }
    }
    return 0;
}