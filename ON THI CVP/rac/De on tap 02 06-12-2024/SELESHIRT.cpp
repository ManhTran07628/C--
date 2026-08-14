#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
pair<ll,ll> a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SELESHIRT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll i = 1,j = 1;
    while(i <= n && j <= m) {
        if()
    }
    return 0;
}