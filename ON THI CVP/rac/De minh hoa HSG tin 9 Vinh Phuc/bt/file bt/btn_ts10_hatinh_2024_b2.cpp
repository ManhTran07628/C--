#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],c[N];

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
    for(int i = 1;i <= N;i++) {
        for(ll j = i;j <= N;j+=i) {
            a[j]++;
        }
    }
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        max1 = max(max1,a[c[i]]);
    }
    cout << max1;
    return 0;
}