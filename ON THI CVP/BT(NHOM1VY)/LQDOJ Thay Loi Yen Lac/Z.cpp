#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll tung[N],truc[N];
pair<ll,ll> f[N];
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
    ll n,a,b;
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++) {
        cin >> f[i].first >> f[i].second;
    }
    sort(f+1,f+n+1);
    ll i = 1,j = 1,min1 = 1e9,kt = 0;
    while(i <= n && j <= n) {
        tung[j] = tung[j-1];
        truc[j] = truc[j-1];
        if(f[j].second == 1) tung[j]++;
        else truc[j]++;
        if(tung[j] - tung[i-1] >= a && truc[j] - truc[i-1] >= b) {
            min1 = min(min1,f[j].first - f[i].first);
            kt = 1;
            i++;
        }
        else j++;
    }
    if(kt) cout << min1;
    else cout << -1;
    return 0;
}