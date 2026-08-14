#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
set<ll> s;
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
    string k;
    cin >> k;
    ll tong = 0,dempt = 0,trung = 0;
    for(int i = 0;i < k.size();i++) {
        cout << s.size() << " ";
        s.insert(k[i]);
        dempt++;
        cout << s.size() << " ";
        if(s.size() == 3) {
            s.erase(s.begin());
            dempt = 2;
            trung++;
        }
        cout << s.size() << " ";
        tong += dempt*(dempt-1) / 2 + dempt;
    }
    cout << tong - trung;
    return 0;
}