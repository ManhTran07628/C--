#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N];
vector<ll> b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "3PRIME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,dem = 0;
    cin >> n;
    for(ll i = 0;i <= N;i++) a[i] = 1;
    a[0]=a[1]=0;
    for(ll i = 1;i <= N;i++)
        if(a[i])
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
    for(int i = 1;i <= 35;i++) {
        for(int i = i+1;i <= )
    }
    // for(int i = 1;i < N;i++) 
    //     if(a[i]) b.push_back(i);
    // ll n1 = upper_bound(b.begin(),b.end(),n) - b.begin();
    // for(int i = 0;i < n1-1;i++) 
    //     for(int j = i+1;j < n1;j++) 
    //         if(b[i] + b[j] <= n) 
    //             dem += a[b[i]+b[j]];
    //         else break;
    // cout << dem;
    return 0;
}
