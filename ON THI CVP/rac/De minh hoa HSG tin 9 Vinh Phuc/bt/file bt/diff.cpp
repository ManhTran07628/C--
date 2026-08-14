#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "diff"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        ll min1 = 0,max1 = 0;
        for(int i = 1;i <= (n-m);i++) {
            min1 += a[i];
        }
        for(int i = n;i > m;i--) {
            max1 += a[i];
        }
        cout << abs(min1-max1) << '\n';
    }
    return 0;
}