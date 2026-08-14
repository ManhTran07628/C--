#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+7;
ll a[N];
map<ll,ll> b;

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
    ll max1 = 0,tmp = 0;
    b[0] = 0;
    for(ll i = 1;i <= n;i++) {
        if(a[i] == 1) tmp++;
        else tmp--;
        if(tmp == 0) {
            max1 = max(max1,i);
            continue;
        }
        if(b[tmp] != 0) {
            max1 = max(max1,i-b[tmp]);
        }
        else b[tmp] = i;
    }
    cout << max1;
    return 0;
}