#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N];
map<ll,vector<ll>> b;
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
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    ll dem = 0;
    while(q--)
    {
        ll l,r,k;
        cin >> l >> r >> k;
        ll dau = lower_bound(b[k].begin(),b[k].end(),l) - b[k].begin();
        ll cuoi = upper_bound(b[k].begin(),b[k].end(),r) - b[k].begin();
        cout << cuoi - dau << '\n';
    }
    return 0;
}