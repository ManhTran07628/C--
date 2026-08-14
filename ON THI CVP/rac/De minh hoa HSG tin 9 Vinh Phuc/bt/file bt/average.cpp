#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
long double a[N],sum[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "average"
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
    long double lo =-1e9,hi = 1e9;
    while(lo <= hi) {
        long double mid = (lo+hi)/2.0;
        if(fabs(lo - mid) <= 0.0000001 && fabs(mid - hi) <= 0.0000001){
            break;
        }
        long double mini = 0;
        for(int i = 1;i <= n;i++) {
            sum[i] = sum[i-1] + a[i] - mid;
        }
        ll kt = 0;
        for(int i = 1;i <= n;i++) {
            if (i >= k) {
                mini = min(mini,sum[i-k]);
                if(sum[i] >= mini) {
                    lo = mid;
                    kt = 1;
                }
            }
        }
        if(kt == 0) hi = mid;
    }
    cout << fixed << setprecision(3) << lo;
    return 0;
}