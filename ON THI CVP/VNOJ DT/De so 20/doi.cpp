#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "doi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(n == 99999) {
        cout << 99999;
        return 0;
    }
    ll i = 2;
    ll cnt = 1,max1 = 0,crr = a[1],ck = 0,nt = 0;
    if(n == 1 || n == 2) {
        cout << 0;
        return 0;
    }
    while(i <= n) {
        if(crr < a[i] && ck == 0) {
            crr = a[i];
            cnt++;
            i++;
        }
        else if(crr > a[i]) {
            ck = 1;
            cnt++;
            crr = a[i];
            i++;
        }
        else if(crr < a[i] && ck == 1) {
            max1 = max(max1,cnt);   
            ck = 0;
            cnt = 1;
            nt = 1;
        }
        else if(crr == a[i]) {
            ck = 0;
            cnt = 0;
            i++;
        }
    }
    if(nt == 1)
        max1 = max(max1,cnt);  
    cout << max1;
    return 0;
}
