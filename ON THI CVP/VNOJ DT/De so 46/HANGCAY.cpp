#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll x[N],r[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "HANGCAY"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> x[i] >> r[i];
        ll x1 = x[i] - r[i];
        if(x1 < 0) x1 = 0;
        for(int j = x1;j <= x[i]+r[i];j++) {
            a[j] = 1;
        }
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i]) cnt++;
    }
    cout << cnt;
    return 0;   
}