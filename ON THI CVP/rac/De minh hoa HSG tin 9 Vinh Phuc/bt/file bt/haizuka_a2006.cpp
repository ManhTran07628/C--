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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    bool kt1 = true;
    bool kt2 = true;
    for(int i = 1;i <= n-1;i++) { // tang dan
        if(a[i] > a[i+1]) {
            kt1 = false;
            break;
        }
    }
    for(int i = 1;i <= n-1;i++) { // giam dan
        if(a[i+1] > a[i]) {
            kt2 = false;
            break;
        }
    }
    if(kt1 == 1 || kt2 == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}   