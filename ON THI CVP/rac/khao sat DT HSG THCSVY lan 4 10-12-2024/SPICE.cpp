#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
map<ll,ll> f;
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
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    ll i = 1,j = 1,cnt = 0;
    while(i <= n && j <= n) {
        while(f[a[i]] != 0) i++;
        if(a[i] == b[j]) {
            i++;
            j++;
        }
        else {
            f[b[j]]++;
            cnt++;
            j++;
        }
    }
    cout << cnt;
    return 0;
}