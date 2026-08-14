#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<pair<ll,ll>> a;
int main()
{
    freopen("MUAHOA.inp","r",stdin);
    freopen("MUAHOA.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        ll a1,a2;
        cin >> a1 >> a2;
        a.push_back({a1,a2});
    }
    sort(a.begin(),a.end());
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        while(m >= a[i].first && a[i].second > 0) {
            m -= a[i].first;
            dem++;
            a[i].second--;
        }
        /*if(m >= (a[i].first * a[i].second)) {
            m -= (a[i].first * a[i].second);
            dem += a[i].second;
        }
        else if(m < (a[i].first * a[i].second) && m >= a[i].first){
            ll sotien = 0;
            ll L = 1,R = a[i].second;
            while(L <= R) {
                ll mid = (L+R)/2;
                ll tmp = a[i].first*mid;
                if(tmp <= m) {
                    sotien = mid;
                    L = mid + 1;
                }
                else {
                    R = mid - 1;
                }
            }
            dem += sotien;
            break;
        }
        */
    }
    cout << dem;
    return 0;
}



