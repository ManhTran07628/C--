#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll t[N],r[N],a[N];

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
    for(int i = 1;i <= n;i++) {
        cin >> t[i];
    }
    for(int i = 1;i <= n-1;i++) {
        cin >> r[i];
    }
    a[1] = t[1];
    a[2] = min(a[1]+t[2],r[1]);
    for(int i = 3;i <= n;i++) {
        a[i] = min(a[i-1] + t[i],a[i-2] + r[i-1]);
    }
    cout << a[n];
    return 0;
}