#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
unordered_map<ll,ll> b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ds"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll tongcap = n*(n-1)/2;
    ll cungso = 0;
    for(auto c:b) {
        cungso += c.second*(c.second-1)/2;
    }
    cout << tongcap - cungso;
    return 0;
}