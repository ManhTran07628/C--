#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N];

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
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    for(int i = 2;i <= k;i++) {
        ll s = i,kt = 0;
        for(int j = 2;j <= sqrt(s);j++) {
            if(s % j == 0) {
                b[j]++;
                kt = 1;
                break;
            }
        }
        if(kt == 0) b[s]++;
    }
    for(int i = 1;i <= n;i++) {
        cout << b[a[i]] << '\n';
    }
    return 0;
}