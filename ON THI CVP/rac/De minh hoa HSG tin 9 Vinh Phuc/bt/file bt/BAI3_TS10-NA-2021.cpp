#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

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
    ll prefix = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        prefix += a[i];
    }
    ll i = 1,j = 1,dem = 0;
    while(i <= n && j <= n) {
        if(j == n+1) {
            i++;
            j = i;
        }
        ll tong = a[i] + a[j];
        if((prefix - tong) % 2 == 0) {
            dem++;
        }
        j++;

    }
    cout << dem;
    return 0;
}