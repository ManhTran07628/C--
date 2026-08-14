#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
long double a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MSTICk"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int l,r;
    cin >> l >> r;
    long double tgmin = 1e9;
    for(int i = l;i <= r;i++) tgmin = min(tgmin,a[i]);

    for(int i = 0;i < n;i++) b[i] = tgmin;

    for(int i = 0;i < l;i++)  b[i] += a[i];

    for(int i = r+1;i < n;i++) b[i] += a[i];
    
    for(int i = l;i <= r;i++) {
        long double crr = (a[i] - tgmin)/2;
        b[i] += crr;
    }
    long double max1 = 0;
    for(int i = 0;i < n;i++) {
         max1 = max(max1,b[i]);
        // cout << fixed << setprecision(1) << b[i] << " ";
    }
    cout << fixed << setprecision(1) << max1;
    return 0;
}