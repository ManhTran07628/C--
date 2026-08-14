#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ds"
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
    ll pos1 = 0,max1 = -1;
    ll count = 1,ptd = a[1],vtd = 1;
    for(int i = 2;i <= n;i++) {
        if((ptd > 0 && a[i] > 0) || (ptd < 0 && a[i] < 0)) count++;
        else if((ptd < 0 && a[i] > 0) || (ptd > 0 && a[i] < 0)){
            if(count >= 2) {
                if(count > max1) {
                    pos1 = vtd;
                    max1 = count;
                }
                count = 1;
            }
            vtd = i;
            ptd = a[i];
        }
    }
    if(count > max1) {
        max1 = count;
        pos1 = vtd;
    }
    if(pos1 == 0) {
        cout << -1;
        return 0;
    }
    cout << max1 << " " << pos1;
    return 0;
}