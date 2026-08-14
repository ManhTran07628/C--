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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll vt = 0,le = 0,vt1 = 0,vt2 = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            if(a[i] % 2 == 0) {
                vt = i;
            }
            if(a[i] % 2 != 0 && le == 0){
                vt1 = i;
                le++;
            }
            else if(a[i] % 2 != 0 && le == 1) {
                vt2 = i;
                le++;
            }
        }
        if(vt != 0) {
            cout << 1 << '\n' << vt << '\n';
            continue;
        }
        if(le == 2) {
            cout << 2 << '\n' << vt1 << " " << vt2 << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
    return 0;
}