#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MinSumOfProduct"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) cin >> b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,greater<ll>());
        ll kq = 0;
        for(int i = 1;i <= n;i++) {
            kq += a[i]*b[i];
        }
        cout << kq << '\n';
    }
    return 0;
}