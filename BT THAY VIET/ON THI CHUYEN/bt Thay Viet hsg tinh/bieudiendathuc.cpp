#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

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
    for(int i = 0;i <= n;i++) {
        cin >> b[i];
    }
    ll l = 0,r = n;
    while(l <= r) {
        a[r] = b[l];
        a[l] = b[r];
        l++;
        r--;
    }
    for(int i = n;i >= 0;i--) {
        if(a[i] != 0) {
            if(a[i] > 0) {
                if(i != n) cout << "+";
            }
            else if(a[i] < 0) cout << "-";
            if(abs(a[i]) != 1) {
                cout << abs(a[i]);
            }
            if(abs(a[i]) == 1 && i == 0) {
                cout << abs(a[i]);
            }
            if(i == 1) cout << "x";
            else if(i > 1) cout << "x^" << i;
        }
    }
    return 0;
}