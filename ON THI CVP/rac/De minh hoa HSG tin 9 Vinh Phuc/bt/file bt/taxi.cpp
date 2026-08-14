#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<ll,ll> b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "taxi"
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
    ll dem = b[4];
    ll m = min(b[1],b[3]);
    dem += min(b[1],b[3]);
    //cout << dem;
    b[1] -= m;
    b[3] -= m;
    dem += b[2] / 2;
    b[2] = b[2] % 2;
    dem += b[3];
    if(b[2] == 1) {
        if(b[1] >= 2) {
            dem++;
            b[2] = 0;
            b[1] -= 2;
        }
    }
    dem += b[1];
    cout << dem;
    return 0;
}
