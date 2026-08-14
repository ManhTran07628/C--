#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<ll> f;
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
        cin >> a[i];
    }
    ll dd = 1,max1 = 1;
    ll vt = a[1];
    for(int i = 2;i <= n;i++) {
        if(vt <= a[i]) {
            dd++;
        }
        else {
            dd = 1;
        }
        vt = a[i];
        max1 = max(max1,dd);
    }
    cout << max1;
    return 0;
}