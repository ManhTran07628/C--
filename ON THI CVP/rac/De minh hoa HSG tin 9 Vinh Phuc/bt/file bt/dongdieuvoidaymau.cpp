#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
ll a[N];
vector<ll> b;
int main()
{
    //freopen("BAI2.inp","r",stdin);
    //freopen("BAI2.out","w",stdout);
    ll n,m;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    while(cin >> m) {
        b.push_back(m);
    }
    int j = 0;
    int kq = 0;
    for(int i = 0;i < b.size();i++) {
        ll tmp = b[i] - a[j];
        if(b[i+1] - a[j+1] == tmp) {
            ll dem = 1;
            while(b[i+1] - a[j+1] == tmp) {
                dem++;
                j++;
                i++;
            }
            if(dem == n) {
                kq++;
            }
            j = 0;
        }
    }
    cout << kq;
    return 0;
}

