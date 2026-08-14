#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
vector<pair<ll,ll>> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "LOOKSAY"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll L,n;
    cin >> L >> n;
    ll maxdukien = -1e9,stt = 0;
    for(int i = 0;i < n;i++) {
        ll a1,a2;
        cin >> a1 >> a2;
        a.push_back({a1,a2});
        if(abs(a2-a1) > maxdukien) {
            stt = i+1;
            maxdukien = abs(a2-a1);
        }
    }
    sort(a.begin(),a.end());
    ll max1 = 0,stt1 = 0;
    for(int i = 0;i < n;i++) {
        if(a[i].first())
    }
    return 0;
}



