#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define dd long double
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dd a,b,c;
    cin >> a >> b >> c;
    ll x = ceil((3*a+b-c)/double(3));
    ll d = max(0ll,x);
    cout << d;
    return 0;
}