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
    ll tong = 0,dempt = 0,trung = 0,vtd = 0;
    for(int i = 0;i < k.size();i++) {
        s.insert(k[i]);
        if(k.size() < 3) {
            continue;
        }
        else {
            tong += (i + vtd+1) * i / 2;
            s.erase(s.begin());
        }
    }
    cout << tong;
    return 0;
}