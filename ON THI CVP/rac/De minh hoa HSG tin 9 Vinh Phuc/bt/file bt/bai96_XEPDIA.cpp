#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<pair<ll,ll>> a;
ll b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "RDISK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll r,h;
        cin >> r >> h;
        a.push_back({r,h});//r ban kinh h chieu cao
    }
    ll max1 =-1e9;
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++) {
        b[i] = a[i].second;
        for (int j = 0; j < i; j++) {
            if (a[j].first < a[i].first && a[j].second < a[i].second) {
                b[i] = max(b[i], b[j] + a[i].second);
            }
        }
        max1 = max(max1, b[i]);
    }
    cout << max1;
    return 0;
}