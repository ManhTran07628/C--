#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TRONGSO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t,kt = 0;
    cin >> t;
    string k1 = "";
    double max1 = 0.0;
    while(t--) {
        string k;
        cin >> k;
        ll dem = 0,vt = 0;
        for(int i = 0;i < k.size();i++) {
            if(isdigit(k[i])) {
                dem+=k[i]-'0';
                vt++;
            }
        }
        if(vt == 0) {
            continue;
        }
        double kq = double(dem) / vt;
        if(max1 < kq) {
            k1 = k;
            max1 = kq;
            kt = 1;
        }
    }
    if(kt == 0) {
        cout << 0;
        return 0;
    }
    cout << k1;
    return 0;
}
// dùng static_cast khi bạn cần chuyển đổi giá trị từ loại này sang loại khác