#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],d[N];

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
    ll n,k
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    fill(d, d + n + 1, LLONG_MAX);
    d[1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            d[i+j] = max(d[i+j], d[i] + max(a[i+j],));
        }
    }
    cout << d[n];
    return 0;
}

