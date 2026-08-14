#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ZFACTOR"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];


    for(int i = 2;i <= k;i++) {
        ll k1 = i;
        ll sol = 0;
        for(int j = 2;j <= sqrt(k1);j++) {
            if(k1 % j == 0) {
                sol = j;
                break;
            }
        }
        if(sol != 0) b[sol]++;
        else b[k1]++;
    }
    for(int i = 1;i <= n;i++) {
        cout << b[a[i]] << "\n";
    }
    return 0;
}