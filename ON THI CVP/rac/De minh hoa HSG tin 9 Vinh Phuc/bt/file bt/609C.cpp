#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    cin >> n;
    ll dem = 0,tbc = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tbc += a[i];
    }
    tbc /= n;
    for(int i = 1;i <= n;i++) {
        if(a[i] < tbc) {
            dem += abs(a[i]-tbc);
        }
    }
    cout << dem;
    return 0;
}