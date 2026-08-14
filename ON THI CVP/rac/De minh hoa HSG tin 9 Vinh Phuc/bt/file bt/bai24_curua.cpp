#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
ll a[N];
vector<ll> b;
int main()
{
    freopen("TURTLE.inp","r",stdin);
    freopen("TURTLE.out","w",stdout);
    for(int i = 1;i <= 4;i++) {
        cin >> a[i];
    }
    sort(a+1,a+5);
    cout << min(a[1],a[2]) * min(a[3],a[4]);
    return 0;
}


