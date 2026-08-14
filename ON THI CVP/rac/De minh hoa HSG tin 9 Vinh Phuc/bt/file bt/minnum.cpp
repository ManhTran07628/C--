#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll n,d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "minnum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,d;
        cin >> n >> d;
        if(d * 9 < n) {
            cout << -1 << '\n';
            continue;
        }
        ll x = n / d;
        ll y = n % d;
        for(int i = 1;i <= d;i++) 
            a[i] = x+(i <= y);
        ll i = 1,j = d;
        while(i < j) {
            ll tmp = min(9-a[j],a[i]-(i==1));
            a[i] -= tmp;
            a[j] += tmp;
            if(a[i] == 1 && i == 1) i++;
            if(a[i] == 0) i++;
            if(a[j] == 9) j--;
        }
        for(int i = 1;i <= d;i++) cout << a[i];
        cout << '\n';
    }
    return 0;
}