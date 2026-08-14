#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N],c[N];
int main()
{
    ll m,n,k;
    ll min1 = 1e9;
    for(int i = 1;i <= 3;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1;i <= 3;i++) {
        for(int j = 1;j <= 3;j++) {
            for(int h = 1;h <= 3;h++) {
                cout << a[i] << " " << b[j] << " " << c[h] << endl;
            }
        }
    }
    cout << min1;
    return 0;
}
