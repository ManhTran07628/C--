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
    for(int i = 1;i <= n+1;i++) 
        cin >> a[i];
    for(int i = 1;i <= n;i++) 
        cin >> b[i];
    ll kq = 0;
    for(int i = 1;i <= n;i++) {
        kq += min(a[i],b[i]);
        b[i] -= min(a[i],b[i]);
        a[i] -= min(a[i],b[i]);
        if(b[i] > 0) {
            kq += min(a[i+1],b[i]);
            a[i+1] -= min(a[i+1],b[i]);
        }
    }
    cout << kq;
    return 0;
}