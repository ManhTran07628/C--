#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
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
    ll n,k;
    cin >> n >> k;
    while(k--) {
        ll l,r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    for(int i = 1;i <= n;i++) {
        a[i] += a[i-1];
        //cout << a[i] << ' ';
    }
    sort(a+1,a+n+1);
    cout << a[(n+1)/2];
    return 0;
}