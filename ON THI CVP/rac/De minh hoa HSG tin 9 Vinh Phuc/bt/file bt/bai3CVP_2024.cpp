#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],d1[N],d2[N],lt1[N],lt2[N];

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
        d1[a[i]]++;
        lt1[d1[a[i]]]++;
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        d2[b[i]]++;
        lt2[d2[b[i]]]++;
    }
    while(q--) {
        ll k;
        cin >> k;
        cout << lt1[k] << " " << lt2[k] << '\n';
    }
    return 0;
}