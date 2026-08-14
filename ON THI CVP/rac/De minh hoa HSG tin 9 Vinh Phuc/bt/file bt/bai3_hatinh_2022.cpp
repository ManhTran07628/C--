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
    ll n,S;
    cin >> n >> S;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    ll kq = 0;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n / 2+1;i++) {
        ll vtd = lower_bound(a+i,a+n+1,S-a[i]) - a;
        ll vtc = upper_bound(a+i,a+n+1,S-a[i]) - a;
        kq += vtc - vtd;
    }
    cout << kq;
    return 0;
}
// 2 3 5 6 8
