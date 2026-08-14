#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
vector<ll> c;
int main()
{
    freopen("LAMDEP.inp","r",stdin);
    freopen("LAMDEP.out","w",stdout);
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+1+n);
    ll vtd,vtc = -1e9,min1 = 1e9;
    for(int i = 4;i <= n;i++) {
        ll tmp = b[i] - b[i-3];
        if(tmp <= min1 && i > vtc) {
            min1 = tmp;
            vtc = i;
            vtd = i-3;
        }
    }
    cout << min1 << endl;
    for(int i = vtd;i <= vtc;i++) {
        c.push_back(b[i]);
    }
    for(int i = 1;i <= n;i++) {
        ll L = 0,R = 3;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(c[mid] == a[i]) {
                cout << i << " ";
                break;
            }
            else if(c[mid] > a[i]) {
                R = mid-1;
            }
            else if(c[mid] < a[i]){
                L = mid+1;
            }
        }
    }
    return 0;
}


