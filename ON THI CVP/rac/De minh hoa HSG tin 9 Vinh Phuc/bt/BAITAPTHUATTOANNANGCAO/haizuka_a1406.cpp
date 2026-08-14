#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll b[N];
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
    ll tmp = 1e9;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        tmp = min(tmp,a[i]);
        b[i] = tmp;
    }
    ll q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        cout << b[k] << '\n';
    }
    return 0;
}