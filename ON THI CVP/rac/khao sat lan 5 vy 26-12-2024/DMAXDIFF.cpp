#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
ll n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DMAXDIFF"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll crr,res = 0;
        if(i == 1) {
            crr = a[i];
        }
        else {
            crr = a[j];
            for(int j = 1;j < i;j++) {
                ans = max(ans,a[j+1]-crr);
                crr = a[j+1];
            }
        }
        
    }
    return 0;
}