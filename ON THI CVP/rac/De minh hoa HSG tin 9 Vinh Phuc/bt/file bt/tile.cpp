#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tile"
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
    sort(a+1,a+n+1);
    if(a[1] == a[n]) {
        cout << 1 << '\n';
        return 0;
    }
    ll dem = 1;
    for(int i = 2;i <= n;i++) {
        if(dem <= a[i]) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}
