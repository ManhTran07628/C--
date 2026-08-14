#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TRUNGTHUONG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        ll max1 = a[i];
        ll min1 = a[i];
        for(int j = i+1;j <= n;j++) {
            max1 = max(a[j],max1);
            min1 = min(a[j],min1);
            if((a[j] == max1 && a[i] == min1) || (a[j] == min1 && a[i] == max1)) {
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}

