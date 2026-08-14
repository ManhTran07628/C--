#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
ll tns = 1e6;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TB"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ll tmp = a[i] + tns;
        b[tmp*2]++;
    }
    sort(a+1,a+n+1);
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            dem += b[a[i]+a[j]+tns+tns];
        }
    }
    cout << dem;
    return 0;
}