#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DELK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    ll tong = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tong += a[i];
    }
    sort(a+1,a+n+1);
    ll i = 1,j = n;
    while(k--) {
        ll dau = a[i] + a[i+1]; // 5 6 10
        ll cuoi = a[j];
        if(dau < cuoi) {
            tong -= dau;
            i+=2;
        }
        else {
            tong -= cuoi;
            j--;
        }
    }
    cout << tong;
    return 0;
}