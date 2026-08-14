#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int main()
{
    freopen("khuyenmai.inp","r",stdin);
    freopen("khuyenmai.out","w",stdout);
    ll a,b,n,c;
    cin >> a >> b >> c >> n;
    ll sosachcl = n / (a+b);
    ll tongsachdangco = sosachcl * (a+b);
    ll sosachthieu = n - tongsachdangco;
    ll sotien = sosachcl*a*c;
    sotien += min(sosachthieu,a) * c;
    cout << sotien;
    return 0;
}
