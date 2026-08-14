#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
vector<ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SORT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,t;
    cin >> n >> m >> t;
    ll cnt = n/m,i = 0,l = 0,r = n/m*m;
    t = t - cnt;
    while(t > 0) {
        i++;l++;r++;
        if(l == 1) cnt++;
        if(r > n) {
            r -= m;
            cnt--;
        }
        t -= cnt;
    }
    t += cnt - (i!=0);
    cout << t * m + i;
    return 0;
}