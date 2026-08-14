#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,vector<ll>> a;
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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        a[b[i]].push_back(i);
    }
    while(k--) {
        ll l;
        cin >> l;
        ll vtd = lower_bound(a.begin(),a)
    }
    return 0;
}