#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    for(int i = 1;i <= m;i++) 
        cin >> a[i];
    ll stt = 1;
    for(int i = 1;i <= N;i++) {
        ll tmp = i;
        ll kt = 1;
        while(tmp > 0) {
            ll tm = tmp % 10;
            for(int j = 1;j <= m;j++) {
                if(tm == a[j]) {
                    kt = -1;
                    break;
                }
            }
            if(tm == -1) {
                break;
            }
            tmp /= 10;
        }
        if(kt == 1) {
            if(stt == n) {
                cout << i;
                return 0;
            }
            stt++;
        }
    }
    return 0;
}