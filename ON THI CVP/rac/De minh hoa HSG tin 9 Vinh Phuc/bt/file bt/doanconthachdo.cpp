#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll s;
    cin >> s;
    ll max1 = -1;
    for(int i = 1;i <= n;i++) {
        ll L = 1,R = n;
        ll vt = -1;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(b[mid] - b[i-1] == s) {
                vt = mid - i + 1;
                break;
            }
            else if(b[mid] - b[i-1] > s) {
                R = mid - 1;
            }
            else if (b[mid] - b[i-1] < s) {
                L = mid + 1;
            }
        }
        max1 = max(max1,vt);
    }
    cout << max1;
    return 0;
}
