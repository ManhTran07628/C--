#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int main()
{
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    if((y-x) % (a+b) == 0) {
        cout << (y-x) / (a+b);
    }
    else {
        cout << -1;
    }
    return 0;
}

