#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];


ll chuyenso(ll k)
{
    vector<ll> b;
    ll demso = 0;
    while(k > 0) {
        ll tmp = k % 10;
        b.push_back(tmp);
        demso++;
        k/=10;
    }
    ll kq = 0;
    for(int i = 0;i < demso;i++) {
        kq = kq + b[i]*pow(2,i);
    }
    return kq;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BAI2"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a1,b;
    cin >> a1 >> b;
    ll vtd = chuyenso(a1);
    ll vtc = chuyenso(b);
    ll kq1 = ceil(sqrt(vtd));
    ll kq2 = ceil(sqrt(vtc));
    cout << abs(kq1-kq2);
    return 0;
}
