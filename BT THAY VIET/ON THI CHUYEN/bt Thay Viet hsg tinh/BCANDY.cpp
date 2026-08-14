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
    ll n;
    ll sum = 0,ma = 1e9;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
        ma = min(ma,a[i]);
    }
    ll e;
    cin >> e;
    if(e > sum) {
        cout<<"impossible";
        return 0;
    }
    ll canchia = sum - ma*n;
    if(canchia > e) {
        cout << "impossible";
        return 0;
    }
    e -= canchia;
    if(e % n == 0) {
        cout << "possible";
    }
    else cout << "impossible";
    return 0;
}