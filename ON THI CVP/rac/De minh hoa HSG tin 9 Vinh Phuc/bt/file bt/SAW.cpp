#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "timx"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll kq = 1e9,vt = -1;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    ll L = 1,R = 1e9;
    while(L <= R){
        ll mid = (L+R)/2;
        ll sum = 0;
        for(int i = 1;i <= n;i++) {
            sum += abs(a[i]-mid);
        }
        if(sum < kq) {
            kq = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << kq;
    return 0;
}