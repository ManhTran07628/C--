#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<pair<ll,ll>> f1,f2;
ll a[N],b[N],p[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "KARATE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        if(b[i] == 0) f1.push_back({a[i],i});
        else f2.push_back({a[i],i});
    }
    for(int i = 0;i < f1.size();i++) {
        ll cnt = 0;
        for(int j = 0;j < i;j++) {
            if(f1[i].fi > f1[j].fi) cnt++;
        }
        p[f1[i].se] = cnt;
    }
     for(int i = 0;i < f2.size();i++) {
        ll cnt = 0;
        for(int j = 0;j < i;j++) {
            if(f2[i].fi > f2[j].fi) cnt++;
        }
        p[f2[i].se] = cnt;
    }
    for(int i = 1;i <= n;i++) {
        cout << p[i] << " ";
    }
    return 0;
}