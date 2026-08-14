#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+2;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cappt"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(b[k-a[i]] > 0 && k-a[i] != a[i]) {
            cnt += b[k-a[i]] * b[a[i]];
            b[k-a[i]] = 0;
            b[a[i]] = 0;
        }
        else if(b[k-a[i]] > 0 && k-a[i] == a[i]) {
            cnt += b[a[i]] * (b[a[i]]-1) / 2;
            b[a[i]] = 0;
        }
    }
    cout << cnt;
    return 0;
}