#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    ll m;
    cin >> m;
    ll crr = 1,sum = 0,length = -1,ans = 0;
    for(int i = 1;i <= m;i+=2) {
        sum += i;
        while(sum > m) {
            sum -= crr;
            crr+=2;
        }
        if(sum == m) {
            ll l = (i-crr)/2+1;
            if(l >= length) {
                length = max(length,l);
                ans = (crr+i)/2;
            }
        }
    }
    cout << ans;
    return 0;
}