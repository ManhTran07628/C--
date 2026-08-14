#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        ll min1 = a[i];ll max1 = a[i];
        for(int j = i + 1;j <= n;j++) {
            min1 = min(min1,a[j]);
            max1 = max(max1,a[j]);
            if(max1 - min1 == k) cnt++;
        }
    }
    cout << cnt;
    return 0;
}