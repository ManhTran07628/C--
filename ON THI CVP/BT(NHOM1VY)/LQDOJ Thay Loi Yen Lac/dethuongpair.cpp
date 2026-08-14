#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],lmin[N],p[N];
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
    fill(lmin,lmin+n+1,1e9);
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        lmin[i] = min(lmin[i-1],a[i]);
        if(lmin[i] == lmin[i-1]) {
            p[i] = p[i-1];
        }
        else p[i] = i;
    }
    for(int i = 1;i <= n;i++) {
        max1 = max(max1,a[i]-lmin[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] - lmin[i] == max1) {
            cout << p[i] << " " << i << '\n' << max1;
            return 0;
        }
    }
    return 0;
}