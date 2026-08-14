#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
vector<ll> b;
int main()
{
    freopen("activity.inp","r",stdin);
    freopen("activity.out","w",stdout);
    ll n,x;
    cin >> n >> x;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    ll i = 0,j = n-1;
    ll dem = 0;
    while(i <= j) {
        if(a[i] + a[j] <= x) {
            dem++;
            j--;
            i++;
        }
        else if(a[i] + a[j] > x) {
            j--;
            dem++;
        }
    }
    cout << dem;
    return 0;
}



