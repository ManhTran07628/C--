#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "trangtri"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        ll pos = 1,check = a[i];
        for(int j = i+1;j <= n;j++) {
            if(abs(a[j]-check) <= k) {
                pos++;
                check = a[j];
            } 
        }
        max1 = max(max1,pos);
    }
    cout << max1;
    return 0;
}