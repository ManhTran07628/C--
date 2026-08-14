#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
map<ll,ll> c;
ll tmp = 1e7;

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
    c[0] = 1;
    ll dem = 0;
    ll tongtt = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tongtt += a[i];
        dem += c[tongtt-k];
        c[tongtt]++;
    }
    cout << dem;
    return 0;
}

