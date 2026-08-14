#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
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
    ll b1,r1,b2,r2;
    cin >> b1 >> r1 >> b2 >> r2;
    b1 -= b2;
    r1 -= r2;
    if(b1 == 0) {
        if(r1 > 0) cout << "correct";
        else cout << "incorrect";
        return 0;
    }
    else if(b1 > 0) {
        if(r1 >= 0) cout << "correct";
        else if(abs(b1) >= abs(r1)) cout << "correct";
        else cout << "unknown";
    }
    else {
        if(r1 <= 0) cout << "incorrect";
        else if(abs(b1) >= abs(r1)) cout << "incorrect";
        else cout << "unknown";
    }
    return 0;
}